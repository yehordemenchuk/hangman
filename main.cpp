#include "mainwindow.h"

#include <QApplication>
#include <cstdlib>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w(nullptr, &a);

    w.show();

    a.exec();

    return EXIT_SUCCESS;
}
