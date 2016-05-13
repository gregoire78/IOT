#include "performances.h"
#include "ui_performances.h"
#include "mycpu.h"

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
    myCpu.cpuPcent();
}

void performances::on_doubleSpinBox_valueChanged(double arg1)
{
    MyCPU myCpu;
    myCpu.cpuPcent();
}

void performances::on_lcdNumberCpu_overflow()
{

}
