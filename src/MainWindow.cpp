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
    QWidget *centralWidget = new QWidget(this);
    QWidget *outputWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    setMenuWidget(outputWidget);
    setAttribute(Qt::WA_TranslucentBackground);

    //   ----- ----- ----- Style  ----- ----- ----- //
    centralWidget->setStyleSheet(
        //"QWidget { background-color: #2b2b2b; }"
        "QLineEdit { "
        "   background-color: #2b2b2b;"
        "   color: #ffffffff;"
        "   border: 2px solid #4b4b4b;"
        "   border-radius: 5px;"
        "   padding: 5px;"
        "   font-size: 14px;"
        "}");
    //  ----- ----- ----- Layout - INPUT ----- ----- ----- //
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->addWidget(inputField, 0, Qt::AlignTop);
    inputField->setAlignment(Qt::AlignCenter);
    connect(inputField, &QLineEdit::returnPressed, this, &MainWindow::processInput);

    //  ----- ----- ----- Layout - OUTPUT ----- ----- ----- //
    // https://doc.qt.io/qt-6/qlabel.html
    QVBoxLayout *outputLayout = new QVBoxLayout(outputWidget);

    outputLayout->setContentsMargins(1, 10, 10, 10);
    outputLayout->setSpacing(110);
    outputLayout->addWidget(outputField, 100, Qt::AlignAbsolute);
    outputField->setAlignment(Qt::AlignBottom);
    // connect(outputField, &QLineEdit::returnPressed, this, &MainWindow::doSearchStuff);
    //  QString Qoutput = QString::fromStdString(output);
    //  outputField->setText(Qoutput);
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