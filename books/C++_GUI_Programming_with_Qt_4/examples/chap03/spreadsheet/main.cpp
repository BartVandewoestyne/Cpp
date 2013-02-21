#include <QApplication>

#include "mainwindow.h"

// VERSION THAT WORKS WITH ONLY ONE FILE
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWin;
    mainWin.show();
    return app.exec();
}
// MULTIPLE FILE VERSION
//int main(int argc, char *argv[])
//{
//    QApplication app(argc, argv);
//    MainWindow *mainWin = new MainWindow;
//    mainWin->show();
//    return app.exec();
//}