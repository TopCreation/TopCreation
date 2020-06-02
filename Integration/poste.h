
#ifndef POSTE_H
#define POSTE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class Poste
{
public:
    Poste();
    Poste(int,QString,int,int);
    QString get_nom_poste();
   int get_nbre_heures();
   int get_salaire();
    int get_id_poste();
    void set_id_poste(int id_poste);
    bool ajouter_poste();
    QSqlQueryModel * afficher_poste();
    bool supprimer_poste(int);
     bool modifier_poste(int,QString,int,int);
  QSqlQueryModel * Rechercher_poste(QString);
  QSqlQueryModel * trier_id_poste();
private:
    QString nom_poste;
    int id_poste,nbre_heures,salaire;
};

#endif // POSTE_H
