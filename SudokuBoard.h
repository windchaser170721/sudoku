//
// Created by xtc on 22-12-11.
//

#ifndef TEST_SUDOKUBOARD_H
#define TEST_SUDOKUBOARD_H
#include <stack>
#include <cstring>
using std::stack;

class mainwindow;
static const int NOSOLUTION = 0;
static const int CORRECT = 1;
static const int MULTISOLUTION = 2;
class SudokuBoard {
 public:
  explicit SudokuBoard(mainwindow *parent = nullptr) : parent(parent) {
    mode = false;
  }
 private:
  mainwindow *parent;
  struct Board {
    int board[9][9];
    bool checked[9][9]; // 懒惰更新
    int focusR, focusC;
  };
 public:
  stack<Board *> history;
  int board[9][9]{}, focusR{}, focusC{};
  int solution[9][9]{};
  int start();
  void solve();
  void backup();
  void undo();
  bool mode;
};
#endif //TEST_SUDOKUBOARD_H
