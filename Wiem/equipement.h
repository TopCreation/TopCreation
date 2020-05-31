#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H

#include<QString>
#include<QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>


class equipements
{
    int code,ide;
     QDate date_delivration;
public:
    equipements();
    equipements(int,int,QDate);
    int getcode(){return code;}
    void setcode(int code){this->code=code;}
    void setdate_delivration(QDate date_delivration){this->date_delivration=date_delivration;}
    bool ajouter_equipements();
    QSqlQueryModel * afficher_equipements();
    bool supprimer_equipements(int);
    bool rech(int);
    bool modifier(int,int,QDate);
        QSqlQueryModel * afficher_equipements_ch(int);
        QSqlQueryModel * trierequipements_code();
        QSqlQueryModel * Rechercher(int);

       // bool  rech_equipements(int code);


    ~equipements(){}

};


#endif // EQUIPEMENT_H
