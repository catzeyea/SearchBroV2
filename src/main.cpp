#include <QApplication>
#include <QWidget>
#include <iostream>
#include "MainWindow.hpp"
#include "OutPutWindow.hpp"
#include "KIStuff.hpp"

#include <iostream>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv); // Startet die Qt-Anwendung
    
    MainWindow mainWin;
    mainWin.move(200, 150);     // Fenster 1
    mainWin.resize(800, 600);
    mainWin.show();

    MainWindow2 outWin;
    outWin.move(1050, 1500);     // Fenster 2 leicht versetzt
    outWin.resize(600, 400);
    outWin.show();
    // Zeigt das Fenster an
    // system("clear");
    // KIStuff ki; // Objekt für die Python-Integration
    // ki.UserStuff(); // Ruft die Python-Integration auf
    
    return a.exec(); // Startet die Event-Schleife (hält das Programm am Laufen)
}