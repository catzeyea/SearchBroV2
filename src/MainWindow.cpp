#include "MainWindow.hpp"
#include <QMainWindow>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QWidget>
#include <QDebug>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    inputField = new QLineEdit(this);
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    centralWidget->setStyleSheet(
        "QWidget { background-color: #2b2b2b; }"
        "QLineEdit { "
        "   background-color: #3b3b3b;"
        "   color: #ffffffff;"
        "   border: 2px solid #4b4b4b;"
        "   border-radius: 5px;"
        "   padding: 5px;"
        "   font-size: 14px;"
        "}"
    );

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->addWidget(inputField);

    connect(inputField, &QLineEdit::returnPressed, this, &MainWindow::processInput);
    connect(inputField, &QLineEdit::returnPressed, this, &MainWindow::doSearchStuff);
}

QString MainWindow::processInput() {
    QString inputFieldText = inputField->text();
    qDebug() << "Input Text:" << inputFieldText;
    inputField->clear();

    return inputFieldText;
}



std::string MainWindow::doSearchStuff() {
    std::cout<<"nhm"<< std::endl;
    return "a";

}
MainWindow::~MainWindow() = default;