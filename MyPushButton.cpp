//
// Created by xtc on 22-12-11.
//

#include "MyPushButton.h"
MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent) {}

bool MyPushButton::event(QEvent *e) {
  // TODO 把 focus 交给系统管理
  // 提示 hasFocus
  if (e->type() == QEvent::FocusOut) {
    // setPalette(MyPalette::palNormal);
  } else if (e->type() == QEvent::FocusIn) {
    // setPalette(MyPalette::palFocus);
  }
  return QPushButton::event(e);
}

void MyPushButton::keyPressEvent(QKeyEvent *event) {
  QPushButton::keyPressEvent(event);

}

void MyPushButton::setRC(int rr, int cc) {
  this->r = rr;
  this->c = cc;
  b = 1 + (rr - 1) / 3 * 3 + (cc - 1) / 3;
}

int MyPushButton::getR() const {
  return r;
}

int MyPushButton::getC() const {
  return c;
}

MyPushButton::~MyPushButton() = default;
// MyPushButton