#include <QApplication>
#include "ThreadDialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    ThreadDialog *dialog = new ThreadDialog(); 
    dialog->show();
    return app.exec();
}
