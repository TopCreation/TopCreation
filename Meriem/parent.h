#ifndef PARENT_H
#define PARENT_H
#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Parent
{
    long Num;
    int Idp;
        QString Nom_p,Prenom_p,Adresse;

public:
    Parent();
    Parent(int,QString,QString,long,QString);
    long getIdp(){return Idp;}
    void setIdp(int Idp){this->Idp=Idp;}
    void setNum(long Num){this->Num=Num;}
    void setNom_p(QString Nom_p){this->Nom_p=Nom_p;}
    void setPrenom_p(QString Prenom_p){this->Prenom_p=Prenom_p;}
    void setAdresse(QString Adresse){this->Adresse=Adresse;}
    bool ajouter_p();
    QSqlQueryModel * afficher_p();
        bool modifier_p(int,QString,QString,long,QString);
        bool supprimer_p(int);
        QSqlQueryModel * Recherche_p(int);



    ~Parent(){}


};


#endif // PARENT_H
