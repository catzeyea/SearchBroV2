#include "MainWindow.hpp"
#include <QVBoxLayout>
#include <QWidget>
#include <QDebug>
#include <iostream>

MyWindow::MyWindow(QWidget *parent)
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

    connect(inputField, &QLineEdit::returnPressed, this, &MyWindow::processInput);
    connect(inputField, &QLineEdit::returnPressed, this, &MyWindow::doSearchStuff);
}

QString MyWindow::processInput() {
    QString inputFieldText = inputField->text();
    qDebug() << "Input Text:" << inputFieldText;
    inputField->clear();

    return inputFieldText;
}



std::string MyWindow::doSearchStuff() {
    std::cout << "BlahBlah" << std::endl;
    return "blahbalh";
}
MyWindow::~MyWindow() = default;
