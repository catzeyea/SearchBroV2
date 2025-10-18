#pragma once

#include <QMainWindow>
#include <QLineEdit>
#include <QVBoxLayout>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    QString processInput();
    std::string doSearchStuff(std::string& output);

private:
    QLineEdit *inputField;
};