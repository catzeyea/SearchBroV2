#include "KIStuff.hpp"
#include "MainWindow.hpp"
#include "OutPutWindow.hpp"
#include <QApplication>
#include <QWidget>
#include <iostream>

#include <iostream>

int main(int argc, char *argv[]) {
  system("clear");
  QApplication a(argc, argv); // starting Qt application

  MainWindow mainWin;
  mainWin.move(200, 150); // Main window
  mainWin.resize(800, 600);
  mainWin.show();

  return a.exec(); // starting event loop
}