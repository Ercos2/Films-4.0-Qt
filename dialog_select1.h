#ifndef DIALOG_SELECT1_H
#define DIALOG_SELECT1_H

#include <QDialog>

namespace Ui {
class Dialog_select1;
}

class Dialog_select1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_select1(QWidget *parent = nullptr);
    ~Dialog_select1();

private slots:
    //void on_Dialog_select1_accepted();

    void on_pushButton_next_clicked();

    void on_pushButton_info_clicked();

    void on_pushButton_yes_clicked();

private:
    Ui::Dialog_select1 *ui;
};

#endif // DIALOG_SELECT1_H
