#pragma once

#include <QMainWindow>
#include <QLineEdit>
#include <QVBoxLayout>

class MainWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow2(QWidget *parent = nullptr);
    ~MainWindow2();

    void displayOutput();

private:
    QLineEdit *outputField;
};