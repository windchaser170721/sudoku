#include <QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  mainwindow m;
  m.show();
  return QApplication::exec();
}
