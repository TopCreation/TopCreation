#include "parent.h"
#include<QSqlQuery>
#include<QString>
#include<QDate>
#include<QVariant>
#include<QRadioButton>

Parent::Parent()
{
    Idp=0;
    Nom_p="";
    Prenom_p="";
    Num=00;
    Adresse="";


}
Parent::Parent(int Idp ,QString Nom_p,QString Prenom_p,long Num,QString Adresse)
{
    this->Idp=Idp;
    this->Nom_p=Nom_p;
    this->Prenom_p=Prenom_p;
    this->Num=Num;
    this->Adresse=Adresse;


}

bool Parent::ajouter_p()
{
    QSqlQuery query;

    QString res=QString::number(Idp);
    QString res1=QString::number(Num);


          query.prepare("INSERT INTO Parent (Idp,Nomp,Prenomp,Num,Adresse) "
                        "VALUES (:Idp,  :Nom_p, :Prenom_p, :Num,:Adresse)");
          query.bindValue(":Idp", res);
          query.bindValue(":Nom_p", Nom_p);
          query.bindValue(":Prenom_p", Prenom_p);
          query.bindValue(":Num",res1);
          query.bindValue(":Adresse", Adresse);


          return  query.exec();


}
QSqlQueryModel * Parent::afficher_p()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from Parent ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Idp"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom_p"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom_p "));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Num "));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse "));

    return model;
}
bool Parent::modifier_p(int Idp, QString Nom_p, QString Prenom_p, long Num, QString Adresse)
{
    QSqlQuery query;
    QString res=QString::number(Idp);
    QString res1=QString::number(Num);

    query.prepare("update Parent set Num =:Num ,  Nom_p=:Nom_p, Prenom_p=:Prenom_p, Num=:Num,Adresse=:Adresse where Idp = :Idp");
    query.bindValue(":Idp", res);
    query.bindValue(":Nom_p",Nom_p );
    query.bindValue(":Prenom_p", Prenom_p);
    query.bindValue(":Num", res1);
    query.bindValue(":Adresse", Adresse);

    return query.exec();


}

bool Parent::supprimer_p(int Idp)
{
QSqlQuery query;
QString res= QString::number(Idp);
query.prepare("Delete from Parent where Idp = :Idp ");
query.bindValue(":Idp", res);
return    query.exec();
}
QSqlQueryModel *  Parent::Recherche_p(int Idp)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString res=QString::number(Idp);
    model->setQuery("select * from Parent where (id LIKE '"+res+"%' ) ");

            return  model;


}
