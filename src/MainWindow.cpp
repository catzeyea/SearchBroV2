#include "MainWindow.hpp"
#include "Colors.hpp"
#include <QMainWindow>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QDebug>
#include <iostream>
#include <QSize>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include "qoverload.h"
#include "Actions.hpp"
using namespace color;

Actions ki;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), tabCounter(0)
{
    setWindowTitle("SearchBroV2");
    setMinimumSize(1000, 700);

    //  ----- ----- ----- Window ----- ----- ----- //
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setStyleSheet("background-color: #1a1a1a;");
    setCentralWidget(centralWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    // Tab widget
    tabWidget = new QTabWidget(this);
    tabWidget->setStyleSheet(
        "QTabWidget::pane { border: none; background-color: #1a1a1a; }"
        "QTabBar::tab { "
        "   background-color: #252525; "
        "   color: #999; "
        "   padding: 12px 20px; "
        "   border: none; "
        "   border-bottom: 2px solid #333; "
        "   font-weight: bold;"
        "}"
        "QTabBar::tab:hover { background-color: #303030; color: #ccc; }"
        "QTabBar::tab:selected { "
        "   background-color: #1a1a1a; "
        "   color: #ffffff; "
        "   border-bottom: 2px solid #00d9ff; "
        "}");
    mainLayout->addWidget(tabWidget, 1);

    // Footer
    QWidget *footerWidget = new QWidget();
    footerWidget->setStyleSheet("background-color: #0d0d0d; border-top: 1px solid #333;");
    QHBoxLayout *footerLayout = new QHBoxLayout(footerWidget);
    footerLayout->setContentsMargins(20, 10, 20, 10);
    footerLayout->addStretch();

    QPushButton *addTabButton = new QPushButton("➕ New Tab");
    addTabButton->setStyleSheet(
        "QPushButton { "
        "   background-color: #00d9ff; "
        "   color: #000; "
        "   border: none; "
        "   border-radius: 5px; "
        "   padding: 10px 25px; "
        "   font-weight: bold; "
        "   font-size: 14px; "
        "}"
        "QPushButton:hover { background-color: #00ffff; }"
        "QPushButton:pressed { background-color: #00a8cc; }");
    addTabButton->setCursor(Qt::PointingHandCursor);
    footerLayout->addWidget(addTabButton);

    connect(addTabButton, &QPushButton::clicked, this, &MainWindow::addNewTab);
    mainLayout->addWidget(footerWidget);

    // First tab
    addNewTab();
}

void MainWindow::addNewTab()
{
    QWidget *tabWidget_content = new QWidget();
    tabWidget_content->setStyleSheet("background-color: #1a1a1a;");
    setupTabUI(tabCounter, tabWidget_content);
    tabWidget->addTab(tabWidget_content, "Tab " + QString::number(tabCounter + 1));
    tabCounter++;
}

void MainWindow::setupTabUI(int tabIndex, QWidget *tabWidget_content)
{
    QVBoxLayout *layout = new QVBoxLayout(tabWidget_content);
    layout->setContentsMargins(25, 25, 25, 25);
    layout->setSpacing(15);

    // Input section
    QLabel *inputLabel = new QLabel("Input Message:");
    inputLabel->setStyleSheet("color: #ffffff; font-size: 13px; font-weight: bold; text-transform: uppercase;");
    layout->addWidget(inputLabel);

    QLineEdit *inputField = new QLineEdit(this);
    inputField->setPlaceholderText("Type your message and press Enter...");
    inputField->setMinimumHeight(45);
    inputField->setStyleSheet(
        "QLineEdit { "
        "   background-color: #252525; "
        "   color: #ffffff; "
        "   border: 2px solid #333; "
        "   border-radius: 8px; "
        "   padding: 12px 15px; "
        "   font-size: 14px; "
        "   selection-background-color: #ffffff; "
        "}"
        "QLineEdit:focus { border: 2px solid #00d9ff; }");
    layout->addWidget(inputField);
    inputFields[tabIndex] = inputField;

    // Output section
    QLabel *outputLabel = new QLabel("Response:");
    outputLabel->setStyleSheet("color: #ffffff; font-size: 13px; font-weight: bold; text-transform: uppercase; margin-top: 10px;");
    layout->addWidget(outputLabel);

    QTextEdit *outputField = new QTextEdit(this);
    outputField->setReadOnly(true);
    outputField->setMinimumHeight(200);
    outputField->setStyleSheet(
        "QTextEdit { "
        "   background-color: #2525252f; "
        "   color: #e0e0e0; "
        "   border: 2px solid #3333333a; "
        "   border-radius: 8px; "
        "   padding: 15px; "
        "   font-size: 13px; "
        "   font-family: 'Courier New', monospace; "
        "}"
        "QTextEdit:focus { border: 2px solid #ffffff; }"
        "QScrollBar:vertical { background-color: #252525; border-radius: 5px; }"
        "QScrollBar::handle:vertical { background-color: #ffffff; border-radius: 5px; }"
        "QScrollBar::handle:vertical:hover { background-color: #ffffff; }");

    layout->addWidget(outputField, 1);
    connect(inputField, &QLineEdit::returnPressed, this, [this, tabIndex, outputField, inputField]() {
        QString inputFieldText = inputField->text();
        inputField->clear();

        std::string inputString = inputFieldText.toStdString();
        ki.UserRequest(inputString);
        outputField->setText(QString::fromStdString(ki.getOutput()));
        outputField->ensureCursorVisible();
    });
}

MainWindow::~MainWindow() = default;