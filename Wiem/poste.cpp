#include <QDebug>
//#include "connetion.h"
#include<QSqlQuery>
#include<QString>
#include<QDate>
#include<QVariant>
#include "poste.h"

Poste::Poste()
{
    nom_poste="";
    id_poste=0;
    nbre_heures=0;
    salaire=0;
}
Poste::Poste(int id_poste,QString nom_poste, int nbre_heures, int salaire)
{
  this-> id_poste= id_poste;
  this->nom_poste=nom_poste;
  this->nbre_heures=nbre_heures;
  this->salaire=salaire;
}
QString Poste::get_nom_poste(){return  nom_poste;}
int Poste::get_id_poste(){return  id_poste;}
int Poste::get_nbre_heures(){return  nbre_heures;}
int Poste::get_salaire(){return  salaire;}
void Poste::set_id_poste(int id_poste){this->id_poste=id_poste;}
bool Poste::ajouter_poste()
{
QSqlQuery query;
QString res= QString::number(id_poste);
query.prepare("INSERT INTO Poste (ID_POSTE, NOM_POSTE, NBRE_HEURES, SALAIRE) "
                    "VALUES (:id_poste, :nom_poste,:nbre_heures, :salaire)");
query.bindValue(":id_poste", res);
query.bindValue(":nom_poste", nom_poste);
query.bindValue(":nbre_heures", nbre_heures);
query.bindValue(":salaire", salaire);

return    query.exec();
}

QSqlQueryModel * Poste::afficher_poste()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from Poste");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NomPoste "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nbre_heure"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Salaire"));
    return model;
}

bool Poste::supprimer_poste(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from Poste  where ID_POSTE = :id_poste ");
query.bindValue(":id_poste", res);
return    query.exec();
}

bool Poste::modifier_poste(int idd,QString nom_poste, int nbre_heures, int salaire)
{ QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("UPDATE Poste SET NOM_POSTE=:nom_poste,NBRE_HEURES=:nbre_heures, SALAIRE=:salaire where ID_POSTE=:id_poste");
    query.bindValue(":id_poste",res);
    query.bindValue(":nom_poste",nom_poste);
    query.bindValue(":nbre_heures",nbre_heures);
     query.bindValue(":salaire",salaire);
    return query.exec();

}
QSqlQueryModel *  Poste::Rechercher_poste(QString nom)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString res=QString(nom);
    model->setQuery("select * from Poste where (nom_poste LIKE '"+res+"%' ) ");



            return  model;


}
QSqlQueryModel * Poste::trier_id_poste()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from Poste ORDER BY id_poste");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_poste"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom_poste "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("nbre_heure"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Salaire"));
        return model;
}
