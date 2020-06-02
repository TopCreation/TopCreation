#ifndef ENFANT_H
#define ENFANT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
class Enfant
{public:
    Enfant();
    Enfant(int,QString,QString,QDate,QString);
    QString get_nom();
    QString get_prenom();
    QDate get_dateDeNaissance();
    QString get_Remarque();
    int get_id();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool recherche(int);
    bool modifier(int,QString,QString,QDate,QString);
        QSqlQueryModel * afficher(int);
        QSqlQueryModel * trier();
        QSqlQueryModel * Recherche(int);
private:
    QString nom,prenom,Remarque ;
    QDate dateDeNaissance;
    int id;



};


#endif // ENFANT_H
