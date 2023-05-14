//
// Created by xtc on 22-12-11.
//

#ifndef TEST_MYPUSHBUTTON_H
#define TEST_MYPUSHBUTTON_H
#include <QPushButton>
#include <QEvent>
#include <QKeyEvent>
#include <QDebug>

class MyPushButton : public QPushButton {
 public:

  explicit MyPushButton(QWidget * = nullptr);
  ~MyPushButton() override;
  bool event(QEvent *e) override;
  void keyPressEvent(QKeyEvent *) override;

 private:
  int r{}, c{}, b{};
 public:
  int getR() const;
  int getC() const;
  void setRC(int rr, int cc);

};

namespace MyPalette {
static const QPalette palFocus = QPalette(QColor(255, 120, 0));
static const QPalette palNormal = QPalette();
}
#endif //TEST_MYPUSHBUTTON_H
