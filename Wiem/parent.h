#ifndef PARENT_H
#define PARENT_H
#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Parent
{
    long Num;
    int Idp;
        QString Nomp,Prenomp,Adresse;

public:
    Parent();
    Parent(int,QString,QString,long,QString);
    long getIdp(){return Idp;}
    void setIdp(int Idp){this->Idp=Idp;}
    void setNum(long Num){this->Num=Num;}
    void setNomp(QString Nomp){this->Nomp=Nomp;}
    void setPrenomp(QString Prenomp){this->Prenomp=Prenomp;}
    void setAdresse(QString Adresse){this->Adresse=Adresse;}
    bool ajouter_p();
    QSqlQueryModel * afficher_p();
        bool modifier_p(int,QString,QString,long,QString);
        bool supprimer_p(int);

        QSqlQueryModel * Recherche_p(int);



    ~Parent(){}


};


#endif // PARENT_H
