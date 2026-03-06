#include <QApplication>
#include <QWidget>
#include <iostream>
#include "MainWindow.hpp"
#include "OutPutWindow.hpp"

#include <iostream>

int main(int argc, char *argv[])
{
    system("clear");
    QApplication application(argc, argv); // Startet die Qt-Anwendung

    MainWindow mainWin;
    mainWin.move(200, 150); // Fenster 1
    mainWin.resize(800, 600);
    mainWin.show();

    return application.exec(); // Startet die Event-Schleife (hält das Programm am Laufen)
}