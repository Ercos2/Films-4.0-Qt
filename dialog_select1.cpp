
#include "dialog_select1.h"
#include "ui_dialog_select1.h"
#include "Func.h"

Dialog_select1::Dialog_select1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_select1)
{
    ui->setupUi(this);

        ui->Dia_name->setText(choose(0));                           //select movie
        ui->Dia_ganre->setText(" ");
}

Dialog_select1::~Dialog_select1()
{
    num_film_1 = 1;
    delete ui;
}

void Dialog_select1::on_pushButton_next_clicked()
{
    if (choose(1) == "f") {                                     //f is error if there are no more movie for select
        ErrorMessage((char*)"Больше нечего предложить");
        num_film_1 = 1;
        close();
        return;
    }
    ui->Dia_name->setText(choose(0));                           //if no f, select more
    ui->Dia_ganre->setText(" ");
    return;
}

void Dialog_select1::on_pushButton_info_clicked()
{
    ui->Dia_ganre->setText(get_ganre(num_film_1));              //display ganre on num_film_1
}


void Dialog_select1::on_pushButton_yes_clicked()
{
    SuccessMessage((char*)"Приятного просмотра");
    num_film_1 = 1;
    close();
    return;
}

