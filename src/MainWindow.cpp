#include "MainWindow.hpp"
#include <QVBoxLayout>
#include <QWidget>
#include <QDebug>

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
        "   color: #ffffff;"
        "   border: 2px solid #4b4b4b;"
        "   border-radius: 5px;"
        "   padding: 5px;"
        "   font-size: 14px;"
        "}"
    );

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->addWidget(inputField);

    connect(inputField, &QLineEdit::returnPressed, this, &MyWindow::processInput);
}

QString MyWindow::processInput() {
    QString inputFieldText = inputField->text();
    qDebug() << "Input Text:" << inputFieldText;
    return inputFieldText;
}

MyWindow::~MyWindow() = default;
