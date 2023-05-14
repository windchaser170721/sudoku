//
// Created by xtc on 22-12-11.
//

#include "SudokuBoard.h"
#include "MainWindow.h"
#include "SudokuImpl.h"
// 返回能否成功开始游戏.
int SudokuBoard::start() {
  memcpy(board, parent->initial, sizeof board);
  focusR = focusC = 0;
  // 清空 history
  while (!history.empty()) {
    delete history.top();
    history.pop();
  }
  // 返回 无解/正确/多解
  return solve_sudoku(board, solution);
}
void SudokuBoard::solve() {
  memcpy(board, solution, sizeof solution);
}
void SudokuBoard::backup() {
  auto *a = new Board();
  a->focusR = focusR;
  a->focusC = focusC;
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++) {
      a->board[i][j] = board[i][j];
      a->checked[i][j] = parent->boardBtn[i][j]->isChecked();
    }
  history.push(a);
}
void SudokuBoard::undo() {
  if (history.empty()) return;
  Board *tmp = history.top();
  history.pop();
  focusC = tmp->focusC;
  focusR = tmp->focusR;
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++) {
      board[i][j] = tmp->board[i][j];
      parent->boardBtn[i][j]->setChecked(tmp->checked[i][j]);
    }
  delete tmp;
  parent->repaintAll();
}
