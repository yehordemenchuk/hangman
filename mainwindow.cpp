#include "mainwindow.h"
#include "game.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent, QApplication *application_ptr)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_application_ptr { application_ptr }
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_playButton_clicked()
{
    hide();
    hangman_game();
}

void MainWindow::on_exitButton_clicked()
{
    close();
}
