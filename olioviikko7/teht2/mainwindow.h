#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString op1, op2;
    bool state;
    float result;
    short operat;

    void operandHandler();
    void equalHandler();
    void clearHandler();
    void operatorHandler();
};
#endif // MAINWINDOW_H
