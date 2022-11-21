#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog_select1.h"
#include "dialog_change1.h"
#include "dialog_add1.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //void on_pushButton_insert_clicked();

    //void on_pushButton_choise_clicked();

    void on_pushButton_change_clicked();

    void on_pushButton_select_clicked();

    void on_pushButton_add_clicked();

    //void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Dialog_select1 *select;
    Dialog_change1 *change;
    Dialog_add1 *add;

};

#endif // MAINWINDOW_H
