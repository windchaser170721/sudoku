#include <QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[]) {
  qreal scale = 2;
  qputenv("QT_SCALE_FACTOR", QString::number(scale).toLatin1());
  QApplication a(argc, argv);
  mainwindow m;
  m.show();
  return QApplication::exec();
}
