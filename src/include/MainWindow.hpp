#pragma once

#include <QMainWindow>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QTabWidget>
#include <QMap>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addNewTab();

private:
    void setupTabUI(int tabIndex, QWidget *tabWidget);

    QTabWidget *tabWidget;
    QMap<int, QLineEdit*> inputFields;
    int tabCounter;
};