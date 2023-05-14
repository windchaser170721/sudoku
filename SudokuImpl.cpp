/*
 * Author https://blog.csdn.net/bl0ss0m/article/details/17918705
 * The original paper of dancing link https://arxiv.org/pdf/cs/0011047.pdf
 */

#include <climits>
#include "SudokuImpl.h"

DLX::DLX(vector<vector<int> > &matrix, int m, int n) : _row(m), _col(n), _count(0) {
  Head = new Node;
  Head->up = Head;
  Head->down = Head;
  Head->right = Head;
  Head->left = Head;
  init();
  link(matrix);
}

void DLX::init() {
  Node *newNode;
  for (int ix = 0; ix < _col; ++ix)//表头位置向后插入,构造列对象
  {
    newNode = new Node;
    newNode->up = newNode;
    newNode->down = newNode;
    newNode->right = Head->right;
    newNode->left = Head;
    newNode->right->left = newNode;
    Head->right = newNode;
  }
  for (int ix = 0; ix < _row; ++ix)//表头位置向下插入,构造行对象
  {
    newNode = new Node(_row - ix);//注意序号是_row-ix
    newNode->down = Head->down;
    newNode->up = Head;
    newNode->down->up = newNode;
    Head->down = newNode;
  }
}

void DLX::link(vector<vector<int> > &matrix) {
  Node *current_row, *current_col, *newNode, *current;//当前行对象,当前列对象,新节点,当前节点
  current_row = Head;
  for (int row = 0; row < _row; ++row) {
    current_row = current_row->down;
    current_col = Head;
    for (int col = 0; col < _col; ++col) {
      current_col = current_col->right;

      if (matrix[row][col] == 0)//矩阵上为0的位置不设置节点
        continue;

      newNode = new Node;

      newNode->colRoot = current_col;
      newNode->rowRoot = current_row;//设置当前节点对应的行列对象

      newNode->down = current_col;
      newNode->up = current_col->up;
      newNode->up->down = newNode;
      current_col->up = newNode;//链接当前节点到列双向链尾端

      if (current_row->Size == 0)//行双向链不应该把行对象包含进来
      {
        current_row->right = newNode;
        newNode->left = newNode;
        newNode->right = newNode;
        current_row->Size++;
      }
      current = current_row->right;//设置当前节点(即行对象右的节点)
      newNode->left = current->left;
      newNode->right = current;
      newNode->left->right = newNode;
      current->left = newNode;//链接当前节点到行双向链尾端

      current_col->Size++;
    }
  }
}

void DLX::cover(Node *cRoot)//覆盖列
{
  cRoot->left->right = cRoot->right;
  cRoot->right->left = cRoot->left;//删除该列对象
  Node *i, *j;
  i = cRoot->down;
  while (i != cRoot) {
    j = i->right;
    while (j != i) {
      j->down->up = j->up;
      j->up->down = j->down;
      j->colRoot->Size--;
      j = j->right;
    }
    i = i->down;
  }
}

void DLX::recover(Node *cRoot)//整个算法的精髓!!
{
  Node *i, *j;
  i = cRoot->up;
  while (i != cRoot) {
    j = i->left;
    while (j != i) {
      j->colRoot->Size++;
      j->down->up = j;
      j->up->down = j;
      j = j->left;
    }
    i = i->up;
  }
  cRoot->right->left = cRoot;
  cRoot->left->right = cRoot;
}

void DLX::dfs(int k) {
  if (Head->right == Head) {
    _count++;
    backup = result;
    return;
  }

  Node *cRoot, *c;
  int minSize = INT_MAX;
  for (c = Head->right; c != Head; c = c->right)//根据启发条件选择列对象
  {
    if (c->Size < minSize) {
      minSize = c->Size;
      cRoot = c;
      if (minSize == 1)
        break;
      if (minSize == 0)//有一列为空,失败
        return;
    }
  }
  cover(cRoot);

  Node *current_row, *current;
  for (current_row = cRoot->down; current_row != cRoot; current_row = current_row->down) {
    result.push_back(current_row->rowRoot->Num);//将该行加入result中
    for (current = current_row->right; current != current_row; current = current->right) {
      cover(current->colRoot);
    }
    dfs(k + 1);
    if (_count > 1) return;
    for (current = current_row->left; current != current_row; current = current->left)
      recover(current->colRoot);
    result.pop_back();
  }
  recover(cRoot);
}
// 转化为01矩阵
vector<vector<int> > sudoku2matrix(const int board[9][9]) {
  vector<vector<int> > matrix;
  for (int ix = 0; ix < 81; ++ix) {
    int val = board[ix / 9][ix % 9] < 0 ? -board[ix / 9][ix % 9] : 0;
    vector<int> current_row(324, 0);
    if (val != 0) {
      current_row[ix] = 1;
      current_row[81 + ix / 9 * 9 + val - 1] = 1;
      current_row[162 + ix % 9 * 9 + val - 1] = 1;
      current_row[243 + (ix / 9 / 3 * 3 + ix % 9 / 3) * 9 + val - 1] = 1;
      matrix.push_back(current_row);
      continue;
    }
    for (int jx = 0; jx < 9; ++jx) {
      vector<int> current_row2(324, 0);
      current_row2[ix] = 1;
      current_row2[81 + ix / 9 * 9 + jx] = 1;
      current_row2[162 + ix % 9 * 9 + jx] = 1;
      current_row2[243 + (ix / 9 / 3 * 3 + ix % 9 / 3) * 9 + jx] = 1;
      matrix.push_back(current_row2);
    }
  }
  return matrix;
}

void matrix2sudoku(vector<vector<int> > &matrix, vector<int> result, int solution[9][9])//将01矩阵翻译为数独
{
  for (int ix = 0; ix < 81; ++ix) {
    vector<int> current = matrix[result[ix] - 1];
    int pos = 0, val = 0;
    for (int jx = 0; jx < 81; ++jx) {
      if (current[jx] == 1)
        break;
      ++pos;
    }
    for (int kx = 81; kx < 162; ++kx) {
      if (current[kx] == 1)
        break;
      ++val;
    }
    solution[pos / 9][pos % 9] = -(val % 9 + 1);
  }
}

int solve_sudoku(const int board[9][9], int solution[9][9]) {
  vector<vector<int> > matrix = sudoku2matrix(board);
  DLX sudoku(matrix, matrix.size(), 324);

  sudoku.dfs();
  if (!sudoku.GetCount()) return 0;
  if (solution != nullptr) matrix2sudoku(matrix, sudoku.getResult(), solution);
  return sudoku.GetCount();
}
