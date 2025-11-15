#include "MainWindow.hpp"
#include "Colors.hpp"
#include <QMainWindow>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QWidget>
#include <QDebug>
#include <iostream>
#include <QSize>
#include <QLabel>
#include <QToolBar>
#include "qoverload.h"
#include "KIStuff.hpp"
using namespace color;

KIStuff ki;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    std::string output = ki.getOutput();
    //  ----- ----- ----- Window ----- ----- ----- //
    outputField = new QLineEdit(this);
    inputField = new QLineEdit(this);
    QWidget *inputWidget = new QWidget(this);
    QWidget *outputWidget = new QWidget(this);
    setCentralWidget(inputWidget);
    setMenuWidget(outputWidget);
    setAttribute(Qt::WA_TranslucentBackground);

    // ----- ----- ----- Layout Overall ----- ----- ----- //
    QVBoxLayout *layout = new QVBoxLayout(inputWidget);
    //   ----- ----- ----- Style  ----- ----- ----- //
    inputWidget->setStyleSheet(
        //"QWidget { background-color: #2b2b2b; }"
        "QLineEdit { "
        "   background-color: #2b2b2b;"
        "   color: #ffffffff;"
        "   border: 2px solid #4b4b4b;"
        "   border-radius: 5px;"
        "   padding: 5px;"
        "   font-size: 14px;"
        "}");

    outputWidget->setStyleSheet(
        "QLineEdit { "
        "   background-color: #2b2b2b;"
        "   color: #ffffffff;"
        "   border: 2px solid #4b4b4b;"
        "   border-radius: 5px;"
        "   padding: 5px;"
        "   font-size: 14px;"
        "}");

    //  ----- ----- ----- Layout - INPUT ----- ----- ----- //

    layout->addWidget(inputField);
    inputField->setAlignment(Qt::AlignCenter);

    //  ----- ----- ----- Layout - OUTPUT ----- ----- ----- //

    // https://doc.qt.io/qt-6/qlabel.html

    layout->addWidget(outputField);
    outputField->setAlignment(Qt::AlignCenter);

    //  ----- ----- ----- Signals & Slots ----- ----- ----- //
    connect(inputField, &QLineEdit::returnPressed, this, &MainWindow::processInput);
}
QString MainWindow::processInput()
{
    QString inputFieldText = inputField->text();
    // qDebug() << "Input Text:" << inputFieldText;

    inputField->clear();

    std::string inputString = inputFieldText.toStdString();
    ki.UserStuff(inputString);
    doSearchStuff();
    return inputFieldText;
}

// std::string output = ki.getOutput();

void MainWindow::doSearchStuff()
{
    QString outputFieldText = outputField->text();
    outputField->setText(QString::fromStdString(ki.getOutput()));
}

MainWindow::~MainWindow() = default;