//
// Created by xtc on 22-12-10.
//

#ifndef TEST_MAINWINDOW_H
#define TEST_MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QShortcut>
#include <iostream>
#include "MyPushButton.h"
#include "SudokuBoard.h"
#include "SudokuImpl.h"
#include <cstring>

QT_BEGIN_NAMESPACE
namespace Ui { class mainwindow; }
QT_END_NAMESPACE


class mainwindow : public QMainWindow {
Q_OBJECT
public:
    MyPushButton *boardBtn[9][9]{};
    int initial[9][9]{};

    explicit mainwindow(QWidget *parent = nullptr);

    ~mainwindow() override;

    void focusChangeTo(int r = 0, int c = 0);

    void setMark(bool checked);

    void repaintAll();

    void focusClean();

public slots:

    void on_undo_triggered() { board->undo(); };

    void on_actBrandNew_triggered();

    void on_btnSolve_clicked();

    void on_actionNew_triggered();

    void on_markClear_triggered();

    void on_markAll_triggered();

    void on_markAdd_triggered();

    void on_mark_triggered(bool checked) { setMark(checked); };

    void on_btnMark_clicked(bool checked) { setMark(checked); };

    void on_R1C1_pressed() { focusChangeTo(1, 1); }

    void on_R1C2_pressed() { focusChangeTo(1, 2); }

    void on_R1C3_pressed() { focusChangeTo(1, 3); }

    void on_R1C4_pressed() { focusChangeTo(1, 4); }

    void on_R1C5_pressed() { focusChangeTo(1, 5); }

    void on_R1C6_pressed() { focusChangeTo(1, 6); }

    void on_R1C7_pressed() { focusChangeTo(1, 7); }

    void on_R1C8_pressed() { focusChangeTo(1, 8); }

    void on_R1C9_pressed() { focusChangeTo(1, 9); }

    void on_R2C1_pressed() { focusChangeTo(2, 1); }

    void on_R2C2_pressed() { focusChangeTo(2, 2); }

    void on_R2C3_pressed() { focusChangeTo(2, 3); }

    void on_R2C4_pressed() { focusChangeTo(2, 4); }

    void on_R2C5_pressed() { focusChangeTo(2, 5); }

    void on_R2C6_pressed() { focusChangeTo(2, 6); }

    void on_R2C7_pressed() { focusChangeTo(2, 7); }

    void on_R2C8_pressed() { focusChangeTo(2, 8); }

    void on_R2C9_pressed() { focusChangeTo(2, 9); }

    void on_R3C1_pressed() { focusChangeTo(3, 1); }

    void on_R3C2_pressed() { focusChangeTo(3, 2); }

    void on_R3C3_pressed() { focusChangeTo(3, 3); }

    void on_R3C4_pressed() { focusChangeTo(3, 4); }

    void on_R3C5_pressed() { focusChangeTo(3, 5); }

    void on_R3C6_pressed() { focusChangeTo(3, 6); }

    void on_R3C7_pressed() { focusChangeTo(3, 7); }

    void on_R3C8_pressed() { focusChangeTo(3, 8); }

    void on_R3C9_pressed() { focusChangeTo(3, 9); }

    void on_R4C1_pressed() { focusChangeTo(4, 1); }

    void on_R4C2_pressed() { focusChangeTo(4, 2); }

    void on_R4C3_pressed() { focusChangeTo(4, 3); }

    void on_R4C4_pressed() { focusChangeTo(4, 4); }

    void on_R4C5_pressed() { focusChangeTo(4, 5); }

    void on_R4C6_pressed() { focusChangeTo(4, 6); }

    void on_R4C7_pressed() { focusChangeTo(4, 7); }

    void on_R4C8_pressed() { focusChangeTo(4, 8); }

    void on_R4C9_pressed() { focusChangeTo(4, 9); }

    void on_R5C1_pressed() { focusChangeTo(5, 1); }

    void on_R5C2_pressed() { focusChangeTo(5, 2); }

    void on_R5C3_pressed() { focusChangeTo(5, 3); }

    void on_R5C4_pressed() { focusChangeTo(5, 4); }

    void on_R5C5_pressed() { focusChangeTo(5, 5); }

    void on_R5C6_pressed() { focusChangeTo(5, 6); }

    void on_R5C7_pressed() { focusChangeTo(5, 7); }

    void on_R5C8_pressed() { focusChangeTo(5, 8); }

    void on_R5C9_pressed() { focusChangeTo(5, 9); }

    void on_R6C1_pressed() { focusChangeTo(6, 1); }

    void on_R6C2_pressed() { focusChangeTo(6, 2); }

    void on_R6C3_pressed() { focusChangeTo(6, 3); }

    void on_R6C4_pressed() { focusChangeTo(6, 4); }

    void on_R6C5_pressed() { focusChangeTo(6, 5); }

    void on_R6C6_pressed() { focusChangeTo(6, 6); }

    void on_R6C7_pressed() { focusChangeTo(6, 7); }

    void on_R6C8_pressed() { focusChangeTo(6, 8); }

    void on_R6C9_pressed() { focusChangeTo(6, 9); }

    void on_R7C1_pressed() { focusChangeTo(7, 1); }

    void on_R7C2_pressed() { focusChangeTo(7, 2); }

    void on_R7C3_pressed() { focusChangeTo(7, 3); }

    void on_R7C4_pressed() { focusChangeTo(7, 4); }

    void on_R7C5_pressed() { focusChangeTo(7, 5); }

    void on_R7C6_pressed() { focusChangeTo(7, 6); }

    void on_R7C7_pressed() { focusChangeTo(7, 7); }

    void on_R7C8_pressed() { focusChangeTo(7, 8); }

    void on_R7C9_pressed() { focusChangeTo(7, 9); }

    void on_R8C1_pressed() { focusChangeTo(8, 1); }

    void on_R8C2_pressed() { focusChangeTo(8, 2); }

    void on_R8C3_pressed() { focusChangeTo(8, 3); }

    void on_R8C4_pressed() { focusChangeTo(8, 4); }

    void on_R8C5_pressed() { focusChangeTo(8, 5); }

    void on_R8C6_pressed() { focusChangeTo(8, 6); }

    void on_R8C7_pressed() { focusChangeTo(8, 7); }

    void on_R8C8_pressed() { focusChangeTo(8, 8); }

    void on_R8C9_pressed() { focusChangeTo(8, 9); }

    void on_R9C1_pressed() { focusChangeTo(9, 1); }

    void on_R9C2_pressed() { focusChangeTo(9, 2); }

    void on_R9C3_pressed() { focusChangeTo(9, 3); }

    void on_R9C4_pressed() { focusChangeTo(9, 4); }

    void on_R9C5_pressed() { focusChangeTo(9, 5); }

    void on_R9C6_pressed() { focusChangeTo(9, 6); }

    void on_R9C7_pressed() { focusChangeTo(9, 7); }

    void on_R9C8_pressed() { focusChangeTo(9, 8); }

    void on_R9C9_pressed() { focusChangeTo(9, 9); }

    void on_btn0_clicked();

    void on_btn1_clicked();

    void on_btn2_clicked();

    void on_btn3_clicked();

    void on_btn4_clicked();

    void on_btn5_clicked();

    void on_btn6_clicked();

    void on_btn7_clicked();

    void on_btn8_clicked();

    void on_btn9_clicked();

private:
    Ui::mainwindow *ui;
    QLabel *label;
    SudokuBoard *board{};

    void initBoard();

    void debug();

    void press(int, bool);

    void initShortcuts();

    void repaintBtnTextAndStyle(int i, int j);

    const int B[3][2] = {{1,  2},
                         {-1, 1},
                         {-2, -1}};
};

#endif //TEST_MAINWINDOW_H
