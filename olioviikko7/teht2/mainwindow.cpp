#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , state(0), result(0.0)
{
    ui->setupUi(this);
    connect(ui->n1, &QPushButton::clicked, this, &MainWindow::operandHandler);
    connect(ui->n2, &QPushButton::clicked, this, &MainWindow::operandHandler);
    connect(ui->n3, &QPushButton::clicked, this, &MainWindow::operandHandler);
    connect(ui->n4, &QPushButton::clicked, this, &MainWindow::operandHandler);
    connect(ui->n5, &QPushButton::clicked, this, &MainWindow::operandHandler);
    connect(ui->n6, &QPushButton::clicked, this, &MainWindow::operandHandler);
    connect(ui->n7, &QPushButton::clicked, this, &MainWindow::operandHandler);
    connect(ui->n8, &QPushButton::clicked, this, &MainWindow::operandHandler);
    connect(ui->n9, &QPushButton::clicked, this, &MainWindow::operandHandler);
    connect(ui->n0, &QPushButton::clicked, this, &MainWindow::operandHandler);


    connect(ui->equal, &QPushButton::clicked, this, &MainWindow::equalHandler);
    connect(ui->clear, &QPushButton::clicked, this, &MainWindow::clearHandler);

    connect(ui->o1add, &QPushButton::clicked, this, &MainWindow::operatorHandler);
    connect(ui->o2sub, &QPushButton::clicked, this, &MainWindow::operatorHandler);
    connect(ui->o3mul, &QPushButton::clicked, this, &MainWindow::operatorHandler);
    connect(ui->o4div, &QPushButton::clicked, this, &MainWindow::operatorHandler);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::operandHandler(){
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    QString buttonText = button->text();

    qDebug() << "Operand pressed:" << buttonText;

    if (!state) {
        op1.append(buttonText);

        if (op1 != "0" && op1.startsWith("0")) {
            op1.remove(0, 1);
        }

        ui->op1->setText(op1);
    } else {
        op2.append(buttonText);

        if (op2 != "0" && op2.startsWith("0")) {
            op2.remove(0, 1);
        }

        ui->op2->setText(op2);
    }
}

void MainWindow::equalHandler(){
    if (op2.isEmpty()) {
        ui->result->setText(op1);
        return;
    }

    float op1f = op1.toFloat();
    float op2f = op2.toFloat();

    switch (operat) {
        case 0:
            result = op1f + op2f;
            break;
        case 1:
            result = op1f - op2f;
            break;
        case 2:
            result = op1f * op2f;
            break;
        case 3:
            if (op2f != 0) {
                result = op1f / op2f;
            } else {
                ui->result->setText("undefined");
                return;
            }
            break;
    }

    qDebug() << "Operand 1:" << op1 << "and Operand 2:" << op2;
    qDebug() << "Result:" << result;
    ui->result->setText(QString::number(result));
}

void MainWindow::clearHandler(){
    state = 0;
    op1 = "";
    op2 = "";
    result = 0.0;
    ui->operator_label->clear();
    ui->op1->clear();
    ui->op2->clear();
    ui->result->clear();
}

void MainWindow::operatorHandler(){
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    QString buttonText = button->text();

    if (buttonText == '+') {
        operat = 0;
    } else if (buttonText == '-') {
        operat = 1;
    } else if (buttonText == '*') {
        operat = 2;
    } else if (buttonText == '/') {
        operat = 3;
    }

    qDebug() << "Operator:" << buttonText.trimmed();
    ui->operator_label->setText(buttonText);
    state = 1;
}
