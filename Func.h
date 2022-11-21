#ifndef FUNC_H
#define FUNC_H

#include <QMessageBox>
#include <QSqlDatabase>//>
#include <QSqlQuery>
#include <QComboBox>

extern int num_film_1;                                          //to browse movies by id
extern const int n, g;                                          //const for char mass
extern QSqlDatabase db;
extern QSqlQuery *query;

extern QString choose(int a);                                   //for select-ui, return film-name
extern int insert(QString p_name, QString p_ganre, int w_unw);  //for ad-ui, insert film in db
extern QString get_name(int num_2);                             //return name by id
extern QString get_ganre(int num_2);                            //return ganre by id
extern int get_w_unw(int num_2);                                //return view status by id
extern int change_w_unw(QString name, bool p_w_unw);            //change view status by name
extern int get_num();                                           //return the number of submitted films
extern bool copy_check(QString p_name);                         //searches for duplicate movies by name. 1 - found, 0 - not found
extern void ErrorMessage(char* message);
extern void SuccessMessage(char* message);

#endif // FUNC_H
