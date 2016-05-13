#include "choice.h"
#include "ui_choice.h"
#include "myserver.h"
#include "performances.h"

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
    performances *perf = new performances(this);
    perf->show();
    //Récupérer les données
}

void Choice::on_modifCharge_clicked()
{
    //Récupérer les données
}
