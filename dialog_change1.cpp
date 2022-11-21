
#include "dialog_change1.h"
#include "ui_dialog_change1.h"
#include "Func.h"

Dialog_change1::Dialog_change1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_change1)
{
    ui->setupUi(this);


    ui->Dia_name->addItem(" ");                                     //if there is, display the names for selection
    for (int i = 1; i <= get_num(); ++i) {
         ui->Dia_name->addItem(get_name(i));
    }
}

Dialog_change1::~Dialog_change1()
{
    delete ui;
}

void Dialog_change1::on_Dia_ok_clicked()
{
    int w_unw, a;
    QString name = ui->Dia_name->currentText();
    if (name == " ") {                                                  //check the filling of the fields
        ErrorMessage((char*)"Выберите название");
        return;
    }
    if (ui->Dia_w->isChecked()) w_unw = 1;
    if (ui->Dia_unw->isChecked()) w_unw = 0;
    if (!(ui->Dia_w->isChecked()) && !(ui->Dia_unw->isChecked())) {
       ErrorMessage((char*)"ВЫберите статус просмотра");
       return;
    }
    a = change_w_unw(name, w_unw);                                      //make changes throgh the function
    if (a != 2){                                                        //if no error message is returned, close window
        SuccessMessage((char*)"Статус просмотра изменён");
        close();
        }
    else
        ErrorMessage((char*)"Не удалось изменить статус просмотра");
}

void Dialog_change1::on_Dia_cancel_clicked()
{
    close();
}

