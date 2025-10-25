#include "OutPutWindow.hpp"
#include "Colors.hpp"
#include <QMainWindow>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QWidget>
#include <QDebug>
#include <iostream>
#include <QSize>
#include "KIStuff.hpp"

KIStuff ki2;
MainWindow2::MainWindow2(QWidget *parent)
    : QMainWindow(parent)
{
    outputField = new QLineEdit(this);
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    // #2b2b2b dark gray background
    //  #3b3b3b slightly lighter gray for input field

    setAttribute(Qt::WA_TranslucentBackground);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->addWidget(outputField);

    // connect(outputField, &QLineEdit::returnPressed, this, &MainWindow2::processInput);
    connect(outputField, &QLineEdit::returnPressed, this, &MainWindow2::displayOutput);

    displayOutput();
}

void MainWindow2::displayOutput()
{
    std::string output = ki2.getOutput();
    outputField->setText(QString::fromStdString(output));
    qDebug() << "Output aktualisiert:" << QString::fromStdString(output);
}
MainWindow2::~MainWindow2() = default;