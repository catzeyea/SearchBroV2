#include <QApplication>
#include <QWidget>
#include <iostream>
#include "MainWindow.hpp"
#include "KIStuff.hpp"

#include <iostream>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv); // Startet die Qt-Anwendung
    
    MainWindow w; // Erstellt dein Hauptfenster
    w.show();   // Zeigt das Fenster an
    
    
    KIStuff ki; // Objekt für die Python-Integration
    ki.UserStuff(); // Ruft die Python-Integration auf
    
    return a.exec(); // Startet die Event-Schleife (hält das Programm am Laufen)
}

 