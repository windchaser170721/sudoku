#ifndef TEST_SUDOKUIMPL_H
#define TEST_SUDOKUIMPL_H
#include <vector>
#include <cstdio>
using namespace std;

struct Node {
  Node *up{}, *down{}, *left{}, *right{}, *colRoot{}, *rowRoot{};//上下左右四个指针以及指向行列对象的指针
  int Num;//行对象特有,记录行数
  int Size;//列对象特有,记录该列元素数
  explicit Node(int i = -1) : Num(i), Size(0) {};//构造函数
};

class DLX {
 public:
  DLX(vector<vector<int> > &matrix, int m, int n);
  ~DLX() { delete Head; };//析构有点难写
  void init();
  void link(vector<vector<int> > &matrix);
  void cover(Node *cRoot);
  static void recover(Node *cRoot);
  void dfs(int k = 0);
  vector<int> getResult() const { return backup; }
 private:
  Node *Head;
  vector<int> result;
  vector<int> backup;
  int _row, _col;//记录行列数,更新次数
  int _count;
 public:
  int GetCount() const {
    return _count;
  }
};
int solve_sudoku(const int [9][9], int [9][9]);
#endif //TEST_SUDOKUIMPL_H
