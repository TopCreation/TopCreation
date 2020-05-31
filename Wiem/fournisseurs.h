#ifndef FOURNISSEURS_H
#define FOURNISSEURS_H


#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class fournisseurs
{
    long tel;
    int idf;
        QString nom,prenom,email,adresse;

public:
    fournisseurs();
    fournisseurs(int,long,QString,QString,QString,QString);
    int getid(){return idf;}
    void setid(int idf){this->idf=idf;}
    long gettel(){return tel;}
    void settel(long tel){this->tel=tel;}
    void setnom(QString nom){this->nom=nom;}
    void setprenom(QString prenom){this->prenom=prenom;}
    QString getemail(){return email;}
    void setemail(QString email){this->email=email;}
    QString getadresse(){return adresse;}
    void setadresse(QString adresse){this->adresse=adresse;}

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(long);
    bool rech(long);
        bool modifier(int,long,QString,QString,QString,QString);
        QSqlQueryModel * afficherfournisseurschercher(int);
        QSqlQueryModel * afficher_fournisseurs_ch(int);

        QSqlQueryModel * trier_idf();
        QSqlQueryModel * fournisseurs_equipements();
        QSqlQueryModel * Rechercher(int);


    ~fournisseurs(){}


};


#endif // FOURNISSEURS_H
