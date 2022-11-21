#ifndef DIALOG_ADD1_H
#define DIALOG_ADD1_H

#include <QDialog>

namespace Ui {
class Dialog_add1;
}

class Dialog_add1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_add1(QWidget *parent = nullptr);
    ~Dialog_add1();

private slots:
    //void on_pushButton_ok_clicked();

    //void on_Dialog_add1_accepted();

    //void on_pushButton_cancel_clicked();

    //void on_Dia_ganre_activated(int index);

    void on_Dia_cancel_clicked();

    void on_Dia_ok_clicked();

private:
    Ui::Dialog_add1 *ui;
    //Dialog_add1 *add;
};

#endif // DIALOG_ADD1_H
