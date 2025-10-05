#pragma once

#include <QMainWindow>
#include <QLineEdit>

class MyWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MyWindow(QWidget *parent = nullptr);
    ~MyWindow();

private slots:
    QString processInput();
    //std::string doSearchStuff();
    //void benutzeApiKey();

private:
    QLineEdit *inputField;
};

