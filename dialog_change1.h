#ifndef DIALOG_CHANGE1_H
#define DIALOG_CHANGE1_H

#include <QDialog>

namespace Ui {
class Dialog_change1;
}

class Dialog_change1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_change1(QWidget *parent = nullptr);
    ~Dialog_change1();

private slots:
    //void on_Dialog_change1_accepted();

    //void on_pushButton_2_clicked();

    void on_Dia_ok_clicked();

    void on_Dia_cancel_clicked();

private:
    Ui::Dialog_change1 *ui;
};

#endif // DIALOG_CHANGE1_H
