#ifndef PERFORMANCES_H
#define PERFORMANCES_H

#include <QMainWindow>

namespace Ui {
class performances;
}

class performances : public QMainWindow
{
    Q_OBJECT

public:
    explicit performances(QWidget *parent = 0);
    ~performances();

private slots:
    void on_lcdNumberCpu_overflow();

    void on_doubleSpinBox_valueChanged(double arg1);

    void on_doubleSpinBoxCPU_valueChanged(double arg1);

    void on_lcdNumber_Flux_overflow();

private:
    Ui::performances *ui;
};

#endif // PERFORMANCES_H
