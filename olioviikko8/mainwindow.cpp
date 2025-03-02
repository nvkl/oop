#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , player1Time(0)
    , player2Time(0)
    , currentPlayer(1)
    , gameTime(0)
{
    ui->setupUi(this);
    connect(ui->switch1, &QPushButton::clicked, this, &MainWindow::switchHandler);
    connect(ui->switch2, &QPushButton::clicked, this, &MainWindow::switchHandler);
    connect(ui->sec, &QPushButton::clicked, this, &MainWindow::timeHandler);
    connect(ui->min, &QPushButton::clicked, this, &MainWindow::timeHandler);
    connect(ui->start, &QPushButton::clicked, this, &MainWindow::startHandler);
    connect(ui->stop, &QPushButton::clicked, this, &MainWindow::stopHandler);

    pQTimer = new QTimer(this);
    connect(pQTimer, &QTimer::timeout, this, &MainWindow::updateProgressBar);

    ui->timer1->setValue(gameTime);
    ui->timer2->setValue(gameTime);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::switchHandler() {
    currentPlayer = !currentPlayer;
    ui->switch1->setEnabled(currentPlayer);
    ui->switch2->setEnabled(!currentPlayer);

    if (currentPlayer) {
        setGameInfoText("Player 1 turn", 16);
    } else {
        setGameInfoText("Player 2 turn", 16);
    }
}

void MainWindow::timeHandler() {
    if (sender() == ui->sec) {
        ui->min->setChecked(0);
        gameTime = 120;
        ui->switch1->setText(QString("Switch (" + QString::number(gameTime) + "s)"));
        ui->switch2->setText(QString("Switch (" + QString::number(gameTime) + "s)"));
    }

    if (sender() == ui->min) {
        ui->sec->setChecked(0);
        gameTime = 300;
        ui->switch1->setText(QString("Switch (" + QString::number(gameTime) + "s)"));
        ui->switch2->setText(QString("Switch (" + QString::number(gameTime) + "s)"));
    }

    if (ui->sec->isChecked() || ui->min->isChecked()) {
        ui->start->setEnabled(1);
    } else {
        ui->start->setEnabled(0);
    }

    setGameInfoText("Ready to play", 16);
    ui->timer1->setRange(0, gameTime);
    ui->timer1->setValue(gameTime);
    ui->timer2->setRange(0, gameTime);
    ui->timer2->setValue(gameTime);

}

void MainWindow::startHandler() {
    setGameInfoText("Game started", 16);

    currentPlayer = 1;

    ui->switch1->setEnabled(1);
    ui->sec->setEnabled(0);
    ui->min->setEnabled(0);
    ui->start->setEnabled(0);
    ui->stop->setEnabled(1);

    player1Time = gameTime;
    player2Time = gameTime;

    pQTimer->start(1000);
}

void MainWindow::stopHandler() {
    setGameInfoText("Game stopped", 16);

    pQTimer->stop();

    ui->switch1->setEnabled(0);
    ui->switch2->setEnabled(0);

    ui->sec->setEnabled(1);
    ui->min->setEnabled(1);
    ui->sec->setChecked(0);
    ui->min->setChecked(0);

    ui->stop->setEnabled(0);

    gameTime = 0;
    ui->timer1->setValue(gameTime);
    ui->timer2->setValue(gameTime);
}

void MainWindow::updateProgressBar() {
    if (currentPlayer) {
        if (player1Time > 0) {
            ui->timer1->setValue(--player1Time);
            ui->switch1->setText(QString("Switch (" + QString::number(player1Time) + "s)"));
        } else {
            stopHandler();
            setGameInfoText("Player 2 wins!", 16);
        }
    } else
        if (player2Time > 0) {
            ui->timer2->setValue(--player2Time);
            ui->switch2->setText(QString("Switch (" + QString::number(player2Time) + "s)"));
        } else {
            stopHandler();
            setGameInfoText("Player 1 wins!", 16);
        }
}

void MainWindow::setGameInfoText(QString text , short fontSize) {
    ui->label->setText(text);
    QFont font = ui->label->font();
    font.setPointSize(fontSize);
    ui->label->setFont(font);
}

void MainWindow::timeout() {
    updateProgressBar();
}
