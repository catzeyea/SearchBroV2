#include <QApplication>
#include <QWidget>
#include <iostream>
#include "MainWindow.hpp"
#include "KIStuff.hpp"
 

int main(int argc, char *argv[]) {
    QApplication a(argc, argv); // Startet die Qt-Anwendung
    
    MyWindow w; // Erstellt dein Hauptfenster
    w.show();   // Zeigt das Fenster an
    
    return a.exec(); // Startet die Event-Schleife (hält das Programm am Laufen)
}

