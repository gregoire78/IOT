#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myserver.h"
#include "performances.h"
#include "choice.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    MyServer server;
   QMessageBox::information(this,"Server Running", "Le serveur est entrain de tourner.");
    Choice *choice = new Choice(this);
    choice->show();
}
