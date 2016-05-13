#include "choice.h"
#include "ui_choice.h"
#include "myserver.h"

Choice::Choice(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Choice)
{
    ui->setupUi(this);
}

Choice::~Choice()
{
    delete ui;
}

void Choice::on_recupCharge_clicked()
{
    MyServer server;
    //Récupérer les données
}

void Choice::on_modifCharge_clicked()
{
    MyServer server;
    //Récupérer les données
}
