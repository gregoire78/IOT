#include "performances.h"
#include "ui_performances.h"
#include "mycpu.h"
#include "flux.h"

performances::performances(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::performances)
{
    ui->setupUi(this);
}

performances::~performances()
{
    delete ui;
}

void performances::on_doubleSpinBoxCPU_valueChanged(double arg1)
{
    MyCPU myCpu;
    arg1 = myCpu.cpuPcent();
}

void performances::on_doubleSpinBox_valueChanged(double arg1)
{
    MyCPU myCpu;
    arg1 = myCpu.cpuPcent();
}

void performances::on_lcdNumberCpu_overflow()
{
    MyCPU myCpu;
    double c;
    c = myCpu.cpuPcent();
    QLCDNumber *lcd = new QLCDNumber(this);
    lcd->display(lcd->value()+c);

}

void performances::on_lcdNumber_Flux_overflow()
{
    /*flux myFlux;
    int f;
    f = myFlux.fluxet();*/
}
