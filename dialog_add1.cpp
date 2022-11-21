
#include "dialog_add1.h"
#include "ui_dialog_add1.h"
#include "Func.h"

Dialog_add1::Dialog_add1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_add1)
{
    ui->setupUi(this);                              //display a list of ganres to choose from
    ui->Dia_ganre->addItem(" ");
    ui->Dia_ganre->addItem("Thriller");
    ui->Dia_ganre->addItem("Action");
    ui->Dia_ganre->addItem("Biography");
    ui->Dia_ganre->addItem("Western");
    ui->Dia_ganre->addItem("Detective");
    ui->Dia_ganre->addItem("Documentary");
    ui->Dia_ganre->addItem("Catastrophe");
    ui->Dia_ganre->addItem("Horror");
    ui->Dia_ganre->addItem("Comedy");
    ui->Dia_ganre->addItem("Fiction");
    ui->Dia_ganre->addItem("Melodrama");
    ui->Dia_ganre->addItem("Musical");
    ui->Dia_ganre->addItem("Noir");
    ui->Dia_ganre->addItem("Post-apocalypse");
    ui->Dia_ganre->addItem("Drama");
    ui->Dia_ganre->addItem("Romcom");
}

Dialog_add1::~Dialog_add1()
{
    delete ui;
}

void Dialog_add1::on_Dia_cancel_clicked()
{
    close();
}


void Dialog_add1::on_Dia_ok_clicked()
{
    int w_unw = 0, a = 0;
    QString s_name = ui->Dia_name->text();
    if (s_name.size() < 1) {                                          //check the filling of the fields
       ErrorMessage((char*)"Введите название");
       return;
    }
    QString s_ganre = ui->Dia_ganre->currentText();
    if (s_ganre == " ") {
        ErrorMessage((char*)"ВЫберите жанр");
        return;
    }
    if (ui->Dia_w->isChecked()) w_unw = 1;
    if (ui->Dia_unw->isChecked()) w_unw = 0;
    if (!(ui->Dia_w->isChecked()) && !(ui->Dia_unw->isChecked())) {
       ErrorMessage((char*)"ВЫберите статус просмотра");
       return;
    }
    a = insert(s_name, s_ganre, w_unw);                                 //enter the mivie through the function
    if (a == 1)
        close();                                                        //close the window if a succes signal is returned
    else
        return;
}


