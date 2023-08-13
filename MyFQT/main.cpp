#include <iostream>
#include "mainwindow.h"

#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    MainWindow w;

    w.setFixedSize(532, 460);

    w.show();

    return a.exec();
}
