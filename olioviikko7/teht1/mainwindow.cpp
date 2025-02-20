#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , number(0)
{
    ui->setupUi(this);
    connect(ui->count, &QPushButton::clicked, this, &MainWindow::countHandler);
    connect(ui->reset, &QPushButton::clicked, this, &MainWindow::resetHandler);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::countHandler() {
    ui->number->setText(QString::number(++number));
}

void MainWindow::resetHandler() {
    ui->number->setText(QString::number(number = 0));
}
