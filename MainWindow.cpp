//
// Created by xtc on 22-12-10.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainwindow.h" resolved
//哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈
#include "MainWindow.h"
#include "ui_MainWindow.h"
mainwindow::mainwindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::mainwindow) {
  ui->setupUi(this);
  initBoard();
  initShortcuts();
  label = new QLabel();
  label->setText(tr("中国"));
  label->setMinimumWidth(150);
  this->setAnimated(false);
  ui->statusBar->addWidget(label);

  connect(ui->mark, SIGNAL(triggered(bool)), ui->btnMark, SLOT(setChecked(bool)));
  connect(ui->mark, SIGNAL(triggered(bool)), ui->markAdd, SLOT(setEnabled(bool)));
  connect(ui->mark, SIGNAL(triggered(bool)), ui->markClear, SLOT(setEnabled(bool)));
  connect(ui->mark, SIGNAL(triggered(bool)), ui->markAll, SLOT(setEnabled(bool)));
  connect(ui->btnMark, SIGNAL(clicked(bool)), ui->mark, SLOT(setChecked(bool)));
  connect(ui->btnMark, SIGNAL(clicked(bool)), ui->markAll, SLOT(setEnabled(bool)));
  connect(ui->btnMark, SIGNAL(clicked(bool)), ui->markAdd, SLOT(setEnabled(bool)));
  connect(ui->btnMark, SIGNAL(clicked(bool)), ui->markClear, SLOT(setEnabled(bool)));

  debug();
}

mainwindow::~mainwindow() {
  delete ui;
  delete label;
}
void mainwindow::debug() {
  // ui->R2C2->setStyleSheet(QString::fromUtf8("color:rgb(28, 113, 216);\nfont: 25 8pt \"Noto Serif CJK SC\";"));
}
// 开启/关闭 mark 模式.
void mainwindow::setMark(bool checked) {
  focusClean(); // 强制关闭focu
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++) {
      boardBtn[i][j]->setChecked(false);
      boardBtn[i][j]->setCheckable(checked && !initial[i][j]);
    }
}

void mainwindow::initBoard() {
  board = new SudokuBoard(this);
  boardBtn[0][0] = ui->R1C1;
  boardBtn[0][1] = ui->R1C2;
  boardBtn[0][2] = ui->R1C3;
  boardBtn[0][3] = ui->R1C4;
  boardBtn[0][4] = ui->R1C5;
  boardBtn[0][5] = ui->R1C6;
  boardBtn[0][6] = ui->R1C7;
  boardBtn[0][7] = ui->R1C8;
  boardBtn[0][8] = ui->R1C9;
  boardBtn[1][0] = ui->R2C1;
  boardBtn[1][1] = ui->R2C2;
  boardBtn[1][2] = ui->R2C3;
  boardBtn[1][3] = ui->R2C4;
  boardBtn[1][4] = ui->R2C5;
  boardBtn[1][5] = ui->R2C6;
  boardBtn[1][6] = ui->R2C7;
  boardBtn[1][7] = ui->R2C8;
  boardBtn[1][8] = ui->R2C9;
  boardBtn[2][0] = ui->R3C1;
  boardBtn[2][1] = ui->R3C2;
  boardBtn[2][2] = ui->R3C3;
  boardBtn[2][3] = ui->R3C4;
  boardBtn[2][4] = ui->R3C5;
  boardBtn[2][5] = ui->R3C6;
  boardBtn[2][6] = ui->R3C7;
  boardBtn[2][7] = ui->R3C8;
  boardBtn[2][8] = ui->R3C9;
  boardBtn[3][0] = ui->R4C1;
  boardBtn[3][1] = ui->R4C2;
  boardBtn[3][2] = ui->R4C3;
  boardBtn[3][3] = ui->R4C4;
  boardBtn[3][4] = ui->R4C5;
  boardBtn[3][5] = ui->R4C6;
  boardBtn[3][6] = ui->R4C7;
  boardBtn[3][7] = ui->R4C8;
  boardBtn[3][8] = ui->R4C9;
  boardBtn[4][0] = ui->R5C1;
  boardBtn[4][1] = ui->R5C2;
  boardBtn[4][2] = ui->R5C3;
  boardBtn[4][3] = ui->R5C4;
  boardBtn[4][4] = ui->R5C5;
  boardBtn[4][5] = ui->R5C6;
  boardBtn[4][6] = ui->R5C7;
  boardBtn[4][7] = ui->R5C8;
  boardBtn[4][8] = ui->R5C9;
  boardBtn[5][0] = ui->R6C1;
  boardBtn[5][1] = ui->R6C2;
  boardBtn[5][2] = ui->R6C3;
  boardBtn[5][3] = ui->R6C4;
  boardBtn[5][4] = ui->R6C5;
  boardBtn[5][5] = ui->R6C6;
  boardBtn[5][6] = ui->R6C7;
  boardBtn[5][7] = ui->R6C8;
  boardBtn[5][8] = ui->R6C9;
  boardBtn[6][0] = ui->R7C1;
  boardBtn[6][1] = ui->R7C2;
  boardBtn[6][2] = ui->R7C3;
  boardBtn[6][3] = ui->R7C4;
  boardBtn[6][4] = ui->R7C5;
  boardBtn[6][5] = ui->R7C6;
  boardBtn[6][6] = ui->R7C7;
  boardBtn[6][7] = ui->R7C8;
  boardBtn[6][8] = ui->R7C9;
  boardBtn[7][0] = ui->R8C1;
  boardBtn[7][1] = ui->R8C2;
  boardBtn[7][2] = ui->R8C3;
  boardBtn[7][3] = ui->R8C4;
  boardBtn[7][4] = ui->R8C5;
  boardBtn[7][5] = ui->R8C6;
  boardBtn[7][6] = ui->R8C7;
  boardBtn[7][7] = ui->R8C8;
  boardBtn[7][8] = ui->R8C9;
  boardBtn[8][0] = ui->R9C1;
  boardBtn[8][1] = ui->R9C2;
  boardBtn[8][2] = ui->R9C3;
  boardBtn[8][3] = ui->R9C4;
  boardBtn[8][4] = ui->R9C5;
  boardBtn[8][5] = ui->R9C6;
  boardBtn[8][6] = ui->R9C7;
  boardBtn[8][7] = ui->R9C8;
  boardBtn[8][8] = ui->R9C9;
  ui->R1C1->setRC(1, 1);
  ui->R1C2->setRC(1, 2);
  ui->R1C3->setRC(1, 3);
  ui->R1C4->setRC(1, 4);
  ui->R1C5->setRC(1, 5);
  ui->R1C6->setRC(1, 6);
  ui->R1C7->setRC(1, 7);
  ui->R1C8->setRC(1, 8);
  ui->R1C9->setRC(1, 9);
  ui->R2C1->setRC(2, 1);
  ui->R2C2->setRC(2, 2);
  ui->R2C3->setRC(2, 3);
  ui->R2C4->setRC(2, 4);
  ui->R2C5->setRC(2, 5);
  ui->R2C6->setRC(2, 6);
  ui->R2C7->setRC(2, 7);
  ui->R2C8->setRC(2, 8);
  ui->R2C9->setRC(2, 9);
  ui->R3C1->setRC(3, 1);
  ui->R3C2->setRC(3, 2);
  ui->R3C3->setRC(3, 3);
  ui->R3C4->setRC(3, 4);
  ui->R3C5->setRC(3, 5);
  ui->R3C6->setRC(3, 6);
  ui->R3C7->setRC(3, 7);
  ui->R3C8->setRC(3, 8);
  ui->R3C9->setRC(3, 9);
  ui->R4C1->setRC(4, 1);
  ui->R4C2->setRC(4, 2);
  ui->R4C3->setRC(4, 3);
  ui->R4C4->setRC(4, 4);
  ui->R4C5->setRC(4, 5);
  ui->R4C6->setRC(4, 6);
  ui->R4C7->setRC(4, 7);
  ui->R4C8->setRC(4, 8);
  ui->R4C9->setRC(4, 9);
  ui->R5C1->setRC(5, 1);
  ui->R5C2->setRC(5, 2);
  ui->R5C3->setRC(5, 3);
  ui->R5C4->setRC(5, 4);
  ui->R5C5->setRC(5, 5);
  ui->R5C6->setRC(5, 6);
  ui->R5C7->setRC(5, 7);
  ui->R5C8->setRC(5, 8);
  ui->R5C9->setRC(5, 9);
  ui->R6C1->setRC(6, 1);
  ui->R6C2->setRC(6, 2);
  ui->R6C3->setRC(6, 3);
  ui->R6C4->setRC(6, 4);
  ui->R6C5->setRC(6, 5);
  ui->R6C6->setRC(6, 6);
  ui->R6C7->setRC(6, 7);
  ui->R6C8->setRC(6, 8);
  ui->R6C9->setRC(6, 9);
  ui->R7C1->setRC(7, 1);
  ui->R7C2->setRC(7, 2);
  ui->R7C3->setRC(7, 3);
  ui->R7C4->setRC(7, 4);
  ui->R7C5->setRC(7, 5);
  ui->R7C6->setRC(7, 6);
  ui->R7C7->setRC(7, 7);
  ui->R7C8->setRC(7, 8);
  ui->R7C9->setRC(7, 9);
  ui->R8C1->setRC(8, 1);
  ui->R8C2->setRC(8, 2);
  ui->R8C3->setRC(8, 3);
  ui->R8C4->setRC(8, 4);
  ui->R8C5->setRC(8, 5);
  ui->R8C6->setRC(8, 6);
  ui->R8C7->setRC(8, 7);
  ui->R8C8->setRC(8, 8);
  ui->R8C9->setRC(8, 9);
  ui->R9C1->setRC(9, 1);
  ui->R9C2->setRC(9, 2);
  ui->R9C3->setRC(9, 3);
  ui->R9C4->setRC(9, 4);
  ui->R9C5->setRC(9, 5);
  ui->R9C6->setRC(9, 6);
  ui->R9C7->setRC(9, 7);
  ui->R9C8->setRC(9, 8);
  ui->R9C9->setRC(9, 9);
  // 重绘
  repaintAll();
}
// 除了按钮外观，重设属性.
/*
 * 已知数 黑色 大字
 * 填数   蓝色 大字
 * 候选数  蓝色  小字
 */
void mainwindow::repaintAll() {
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      if (!initial[i][j])
        repaintBtnTextAndStyle(i, j);
}

void mainwindow::repaintBtnTextAndStyle(int i, int j) {
  // TODO 更改设置 StypeSheet 的方式使得与palette不冲突.
  if (board->board[i][j] < 0) {
    boardBtn[i][j]->setText(QString::number(-board->board[i][j]));
    boardBtn[i][j]->setStyleSheet(QString::fromUtf8(
        "text-align:top;\ncolor:rgb(26,95,180);\nfont: 25pt \"Noto Sans Mono\""));
  } else {
    char tmp[9];
    for (int k = 0; k < 9; k++)
      tmp[k] = ((board->board[i][j] >> k) & 1) ? (char) ('1' + k) : ' ';
    boardBtn[i][j]->setText(QString::asprintf("%c   %c   %c\n%c   %c   %c\n%c   %c   %c",
                                              tmp[0],
                                              tmp[1],
                                              tmp[2],
                                              tmp[3],
                                              tmp[4],
                                              tmp[5],
                                              tmp[6],
                                              tmp[7],
                                              tmp[8]));
    boardBtn[i][j]->setStyleSheet(QString::fromUtf8(
        "text-align:left,top;\ncolor:rgb(28, 113, 216);\nfont: 25 8pt \"Noto Serif CJK SC\";"));
  }
  // palette 建议最后更新.
  if (i + 1 == board->focusR && j + 1 == board->focusC)
    boardBtn[i][j]->setPalette(MyPalette::palFocus);
  else
    boardBtn[i][j]->setPalette(MyPalette::palNormal);
}
// 普通模式: 设置focus、 更新至多两个按钮外观
// 标记模式: sync
// 对于click 0 0:

void mainwindow::focusChangeTo(int r, int c) {
  if (board->focusR) {
    boardBtn[board->focusR - 1][board->focusC - 1]->setPalette(MyPalette::palNormal);
  }
  if (!ui->mark->isChecked()) {
    board->focusR = r;
    board->focusC = c;
    // 新的外观
    if (r)
      boardBtn[r - 1][c - 1]->setPalette(MyPalette::palFocus);
  }
}

void mainwindow::on_markAll_triggered() {
  for (auto &i : boardBtn)
    for (auto &j : i)
      if (j->isEnabled())
        j->setChecked(true);
}

void mainwindow::on_markClear_triggered() {
  for (auto &i : boardBtn)
    for (auto &j : i)
      j->setChecked(false);
}

void mainwindow::on_actionNew_triggered() {
  // 所有oor的当作未知处理.
  freopen("/home/xtc/Documents/work/Project0/in", "r", stdin);
  unsigned short x;
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++) {
      scanf("%hu", &x);
      initial[i][j] = (x <= 9) ? -x : 0;
      if (initial[i][j]) {
        boardBtn[i][j]->setPalette(MyPalette::palNormal);
        boardBtn[i][j]->setStyleSheet(QString::fromUtf8(
            "text-align:top;\ncolor:rgb(0,0,0)\n;font: 25pt \"Noto Sans Mono\""));
        boardBtn[i][j]->setText(QString::number(x));
        // 在本局游戏中不改变.
        boardBtn[i][j]->setEnabled(false);
      } else {
        boardBtn[i][j]->setEnabled(true);
      }
      boardBtn[i][j]->setChecked(false);
    }
  switch (board->start()) {
    case NOSOLUTION:label->setText(tr("无解"));
      break;
    case CORRECT:label->setText(tr("就绪"));
      break;
    case MULTISOLUTION:label->setText((tr("警告:不是标准数独")));
      break;
  }
  repaintAll();
}
// 对所有按键的响应, 是填还是候选数
// marked=false: 对合法的焦点和mark填数.
// 不可能存在有focus的mark模式.
// 在mark模式加数: 对所有mark格子, 优先减数；但若所有格子都没有候选这个数或填入这个数，就加数.
// 在focus模式加数： focus格子是候选数，异或；focus格子是填数，加数(不变)
void mainwindow::press(int x, bool marked) {
  board->backup();
  // 填数，根据需要删去作用格的候选数. 只有这里用到
  if (!x) {
    for (int i = 0; i < 9; i++)
      for (int j = 0; j < 9; j++)
        if (boardBtn[i][j]->isChecked()) {
          board->board[i][j] = 0;
          repaintBtnTextAndStyle(i, j);
        }
    if (board->focusR) {
      board->board[board->focusR - 1][board->focusC - 1] = 0;
      repaintBtnTextAndStyle(board->focusR - 1, board->focusC - 1);
    }
    return;
  }
  if (marked) {
    if (board->focusR) {
      int i = board->focusR - 1, j = board->focusC - 1;
      if (board->board[i][j] < 0) {
        if (board->board[i][j] + x)
          board->board[i][j] = (1 << (-board->board[i][j] - 1)) | (1 << (x - 1));
      } else
        board->board[i][j] ^= (1 << (x - 1));
      repaintBtnTextAndStyle(i, j);
    } else {
      bool found = false;
      for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
          if (boardBtn[i][j]->isChecked()) {
            if (!found)
              found = (!(x + board->board[i][j]) || (board->board[i][j] > 0 && ((board->board[i][j] >> (x - 1)) & 1)));
            if (found && board->board[i][j] > 0) {
              board->board[i][j] &= ~(1 << (x - 1));
              repaintBtnTextAndStyle(i, j);
            }
          }
      if (!found)
        for (int i = 0; i < 9; i++)
          for (int j = 0; j < 9; j++)
            if (boardBtn[i][j]->isChecked()) {
              if (board->board[i][j] < 0)
                board->board[i][j] = (1 << (-board->board[i][j] - 1));
              board->board[i][j] ^= (1 << (x - 1));
              repaintBtnTextAndStyle(i, j);
            }
    }
  } else {
    for (int i = 0; i < 9; i++)
      for (int j = 0; j < 9; j++)
        if (boardBtn[i][j]->isChecked()) {
          board->board[i][j] = -x;
          boardBtn[i][j]->setStyleSheet(QString::fromUtf8(
              "text-align:top;\ncolor:rgb(26,95,180);\nfont: 25pt \"Noto Sans Mono\""));
          boardBtn[i][j]->setText(QString::number(x));
          if (ui->checkUpdate->isChecked()) {
            for (int k = 0; k < 9; k++) {
              if (board->board[k][j] > 0) {
                board->board[k][j] &= ~(1 << (x - 1));
                repaintBtnTextAndStyle(k, j);
              }
              if (board->board[i][k] > 0) {
                board->board[i][k] &= ~(1 << (x - 1));
                repaintBtnTextAndStyle(i, k);
              }
            }
            for (int k = 0; k < 2; k++)
              for (int l = 0; l < 2; l++)
                if (board->board[i + B[i % 3][k]][j + B[j % 3][l]] > 0) {
                  board->board[i + B[i % 3][k]][j + B[j % 3][l]] &= ~(1 << (x - 1));
                  repaintBtnTextAndStyle(i + B[i % 3][k], j + B[j % 3][l]);
                }
          }
        }
    if (board->focusR) {
      int i = board->focusR - 1, j = board->focusC - 1;
      board->board[i][j] = -x;
      boardBtn[i][j]->setStyleSheet(QString::fromUtf8(
          "text-align:top;\ncolor:rgb(26,95,180);\nfont: 25pt \"Noto Sans Mono\""));
      boardBtn[i][j]->setPalette(MyPalette::palFocus);
      boardBtn[i][j]->setText(QString::number(x));
      if (ui->checkUpdate->isChecked()) {
        for (int k = 0; k < 9; k++) {
          if (board->board[k][j] > 0) {
            board->board[k][j] &= ~(1 << (x - 1));
            repaintBtnTextAndStyle(k, j);
          }
          if (board->board[i][k] > 0) {
            board->board[i][k] &= ~(1 << (x - 1));
            repaintBtnTextAndStyle(i, k);
          }
        }
        for (int k = 0; k < 2; k++)
          for (int l = 0; l < 2; l++)
            if (board->board[i + B[i % 3][k]][j + B[j % 3][l]] > 0) {
              board->board[i + B[i % 3][k]][j + B[j % 3][l]] &= ~(1 << (x - 1));
              repaintBtnTextAndStyle(i + B[i % 3][k], j + B[j % 3][l]);
            }
      }
    }
  }
}

void mainwindow::on_btn0_clicked() { press(0, ui->mark->isChecked()); }
void mainwindow::on_btn1_clicked() { press(1, ui->mark->isChecked()); }
void mainwindow::on_btn2_clicked() { press(2, ui->mark->isChecked()); }
void mainwindow::on_btn3_clicked() { press(3, ui->mark->isChecked()); }
void mainwindow::on_btn4_clicked() { press(4, ui->mark->isChecked()); }
void mainwindow::on_btn5_clicked() { press(5, ui->mark->isChecked()); }
void mainwindow::on_btn6_clicked() { press(6, ui->mark->isChecked()); }
void mainwindow::on_btn7_clicked() { press(7, ui->mark->isChecked()); }
void mainwindow::on_btn8_clicked() { press(8, ui->mark->isChecked()); }
void mainwindow::on_btn9_clicked() { press(9, ui->mark->isChecked()); }

void mainwindow::initShortcuts() {
  connect(new QShortcut(QKeySequence(Qt::Key_Escape), this), &QShortcut::activated, this, &mainwindow::focusClean);

  connect(new QShortcut(QKeySequence(Qt::Key_0), this),
          &QShortcut::activated,
          this,
          [&]() { press(0, ui->mark->isChecked()); });
  connect(new QShortcut(QKeySequence(Qt::ALT + Qt::Key_0), this),
          &QShortcut::activated,
          this,
          [&]() { press(0, !ui->mark->isChecked()); });
  connect(new QShortcut(QKeySequence(Qt::Key_1), this),
          &QShortcut::activated,
          this,
          [&]() { press(1, ui->mark->isChecked()); });
  connect(new QShortcut(QKeySequence(Qt::ALT + Qt::Key_1), this),
          &QShortcut::activated,
          this,
          [&]() { press(1, !ui->mark->isChecked()); });
  connect(new QShortcut(QKeySequence(Qt::Key_2), this),
          &QShortcut::activated,
          this,
          [&]() { press(2, ui->mark->isChecked()); });
  connect(new QShortcut(QKeySequence(Qt::ALT + Qt::Key_2), this),
          &QShortcut::activated,
          this,
          [&]() { press(2, !ui->mark->isChecked()); });
  connect(new QShortcut(QKeySequence(Qt::Key_3), this),
          &QShortcut::activated,
          this,
          [&]() { press(3, ui->mark->isChecked()); });
  connect(new QShortcut(QKeySequence(Qt::ALT + Qt::Key_3), this),
          &QShortcut::activated,
          this,
          [&]() { press(3, !ui->mark->isChecked()); });
  connect(new QShortcut(QKeySequence(Qt::Key_4), this),
          &QShortcut::activated,
          this,
          [&]() { press(4, ui->mark->isChecked()); });
  connect(new QShortcut(QKeySequence(Qt::ALT + Qt::Key_4), this),
          &QShortcut::activated,
          this,
          [&]() { press(4, !ui->mark->isChecked()); });
  connect(new QShortcut(QKeySequence(Qt::Key_5), this),
          &QShortcut::activated,
          this,
          [&]() { press(5, ui->mark->isChecked()); });
  connect(new QShortcut(QKeySequence(Qt::ALT + Qt::Key_5), this),
          &QShortcut::activated,
          this,
          [&]() { press(5, !ui->mark->isChecked()); });
  connect(new QShortcut(QKeySequence(Qt::Key_6), this),
          &QShortcut::activated,
          this,
          [&]() { press(6, ui->mark->isChecked()); });
  connect(new QShortcut(QKeySequence(Qt::ALT + Qt::Key_6), this),
          &QShortcut::activated,
          this,
          [&]() { press(6, !ui->mark->isChecked()); });
  connect(new QShortcut(QKeySequence(Qt::Key_7), this),
          &QShortcut::activated,
          this,
          [&]() { press(7, ui->mark->isChecked()); });
  connect(new QShortcut(QKeySequence(Qt::ALT + Qt::Key_7), this),
          &QShortcut::activated,
          this,
          [&]() { press(7, !ui->mark->isChecked()); });
  connect(new QShortcut(QKeySequence(Qt::Key_8), this),
          &QShortcut::activated,
          this,
          [&]() { press(8, ui->mark->isChecked()); });
  connect(new QShortcut(QKeySequence(Qt::ALT + Qt::Key_8), this),
          &QShortcut::activated,
          this,
          [&]() { press(8, !ui->mark->isChecked()); });
  connect(new QShortcut(QKeySequence(Qt::Key_9), this),
          &QShortcut::activated,
          this,
          [&]() { press(9, ui->mark->isChecked()); });
  connect(new QShortcut(QKeySequence(Qt::ALT + Qt::Key_9), this),
          &QShortcut::activated,
          this,
          [&]() { press(9, !ui->mark->isChecked()); });
}

void mainwindow::on_markAdd_triggered() {
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      if (boardBtn[i][j]->isChecked()) {
        board->board[i][j] = (1 << 9) - 1;
        for (int k = 0; k < 9; k++) {
          if (k != i && board->board[k][j] < 0)
            board->board[i][j] &= ~(1 << (-board->board[k][j] - 1));
          if (k != j && board->board[i][k] < 0)
            board->board[i][j] &= ~(1 << (-board->board[i][k] - 1));
        }
        for (int k = 0; k < 2; k++)
          for (int l = 0; l < 2; l++) {
            int &tmp = board->board[i + B[i % 3][k]][j + B[j % 3][l]];
            if (tmp < 0)
              board->board[i][j] &= ~(1 << (-tmp - 1));
          }
        repaintBtnTextAndStyle(i, j);
      }
}

void mainwindow::focusClean() {
  if (board->focusR)
    boardBtn[board->focusR - 1][board->focusC - 1]->setPalette(MyPalette::palNormal);
  else
    setFocus();
  board->focusR = board->focusC = 0;
}
void mainwindow::on_btnSolve_clicked() {
  if (board->mode) {
    switch (solve_sudoku(board->board, board->solution)) {
      case 0:label->setText("矛盾");
        break;
      case 1: {
        label->setText("再按一次查看答案");
        board->mode = false;
        break;
      }
      case 2: {
        label->setText("不是标准数独");
        break;
      };
    }
  } else
    board->solve();
  repaintAll();
}
void mainwindow::on_actBrandNew_triggered() {
  board->mode = true;
  memset(initial, 0, sizeof initial);
  memset(board->board, 0, sizeof board->board);
  board->focusR = board->focusC = 0;

  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++) {
      boardBtn[i][j]->setEnabled(true);
      boardBtn[i][j]->setChecked(false);
    }
  repaintAll();
}
