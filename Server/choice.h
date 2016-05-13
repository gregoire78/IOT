#ifndef CHOICE_H
#define CHOICE_H

#include <QMainWindow>

namespace Ui {
class Choice;
}

class Choice : public QMainWindow
{
    Q_OBJECT

public:
    explicit Choice(QWidget *parent = 0);
    ~Choice();

private slots:
    void on_recupCharge_clicked();

    void on_modifCharge_clicked();

private:
    Ui::Choice *ui;
};

#endif // CHOICE_H
