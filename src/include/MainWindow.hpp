#pragma once

#include <QMainWindow>
#include <QLineEdit>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    QString processInput();
    std::string doSearchStuff();
    //void benutzeApiKey();

private:
    QLineEdit *inputField;
};

