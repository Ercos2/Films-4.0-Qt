
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "Func.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");              //create db
    db.setDatabaseName("./filmsDB.db");
    db.open();
    query = new QSqlQuery(db);
    query->exec("CREATE TABLE Films(Id INT PRIMARY KEY NOT NULL, Name TEXT NOT NULL, Ganre TEXT NOT NULL, W_unw INT NOT NULL);");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_select_clicked()
{
    if (choose(0) == "f") {                                     //check if there are movies for select
       ErrorMessage((char*)"Нет фильмов для выбора");
       num_film_1 = 1;
       //close();
    } else {
        Dialog_select1 select;
        select.setModal(true);
        select.exec();
    }
}

void MainWindow::on_pushButton_change_clicked()
{
    if (!get_num()) {                                                   //check if there are movies
        ErrorMessage((char*)"Нeт внесённых фильмов");


    } else {
        Dialog_change1 change;
        change.setModal(true);
        change.exec();
    }
}

void MainWindow::on_pushButton_add_clicked()
{
    Dialog_add1 add;
    add.setModal(true);
    add.exec();
}
