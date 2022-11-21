#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Func.h"

const int n = 50, g = 20;
int num_film_1 = 1;
QSqlDatabase db;
QSqlQuery *query;

QString get_name(int num_2) {
    QString copy_name;
    QString str_num = (QString)"\"" + (char)(num_2 + 48) + (QString)"\"";
    QString sql = "SELECT Name FROM Films WHERE Id = " + str_num + (QString)";";
    query->exec(sql);
    while(query->next()){
        copy_name = query->value(0).toString();
    }
    return copy_name;
}


QString get_ganre(int num_2) {
        QString copy_ganre;
        QString str_num = (QString)"\"" + (char)(num_2 + 48) + (QString)"\"";
        QString sql = "SELECT Ganre FROM Films WHERE Id = " + str_num + (QString)";";
        query->exec(sql);
        while(query->next()){
            copy_ganre = query->value(0).toString();
        }
        return copy_ganre;
    }

int get_w_unw(int num_2) {
    int w_unw;
    QString str_num = (QString)"\"" + (char)(num_2 + 48) + (QString)"\"";
    QString sql = "select W_unw from Films where Id =" + str_num + (QString)";";
    query->exec(sql);
    while(query->next())
        w_unw = query->value(0).toInt();

    return w_unw;
}

int get_num() {
    QString sql = "SELECT count(Id) FROM Films";
    int num_film = 0;
    query->exec(sql);
    while(query->next())
        num_film = query->value(0).toInt();
    return num_film;
}



int change_w_unw(QString name, bool p_w_unw) {
    QString str_w_unw = (QString)"\"" + (char)(p_w_unw + 48) + (QString)"\"";
    QString sql = "update Films set W_unw = " + str_w_unw + (QString)" where Name = '" + name + "'; ";

    query->prepare(sql);
    query->exec();
    return 1;
}



QString choose(int a) {
    num_film_1 += a;
    for (num_film_1; num_film_1 <= get_num(); num_film_1++) {
        if (get_w_unw(num_film_1) == 1) continue;
        else if (get_w_unw(num_film_1) == 2) break;
        else if (get_w_unw(num_film_1) == 0)
            return get_name(num_film_1);
    }
    return (char*)"f";
}

int insert(QString p_name, QString p_ganre, int w_unw) {
    if (copy_check(p_name)) {
        ErrorMessage((char*)"copy found");
        return 2;
    }
    QString id = (QString)"" + (char)(get_num() + 48 + 1) + (QString)"";
    QString str_w_unw = (QString)"" + (char)(w_unw + 48) + (QString)"";
    QString sql = "insert into Films values (" + id + (QString)",'" + p_name + (QString)"','" + p_ganre + (QString)"'," + str_w_unw + (QString)"); ";
    query->prepare(sql);
    if(query->exec()){
        SuccessMessage((char*)"Фильм внесён");
        return 1;
    }
    else {
        ErrorMessage((char*)"Фильм не внесён");
        return 2;
    }
    return 1;
}

bool copy_check(QString p_name) {
    if (get_num() > 0) {
        QString sql = "select Name from Films;";
        QString copy_name;
        query->exec(sql);
        while(query->next()){
             copy_name = query->value(0).toString();
             if(copy_name == p_name)
                return 1;
        }
    }
    return 0;
}

void ErrorMessage(char* message) {
    QMessageBox::warning(NULL, "Warning", message);
}

void SuccessMessage(char* message) {
    QMessageBox::about(NULL, "Success", message);
}

#endif // FUNCTIONS_H
