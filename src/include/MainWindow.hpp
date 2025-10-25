#pragma once

#include <QMainWindow>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    QString processInput();
    void doSearchStuff();

private:
    QLineEdit *inputField;
    QLabel *outputField;
};