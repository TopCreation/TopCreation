#include "parent.h"
#include<QSqlQuery>
#include<QString>
#include<QDate>
#include<QVariant>
#include<QRadioButton>

Parent::Parent()
{
    Idp=0;
    Nomp="";
    Prenomp="";
    Num=00;
    Adresse="";


}
Parent::Parent(int Idp ,QString Nomp,QString Prenomp,long Num,QString Adresse)
{
    this->Idp=Idp;
    this->Nomp=Nomp;
    this->Prenomp=Prenomp;
    this->Num=Num;
    this->Adresse=Adresse;


}

bool Parent::ajouter_p()
{
    QSqlQuery query;

    QString res=QString::number(Idp);
    QString res1=QString::number(Num);


          query.prepare("INSERT INTO Parent (IDP,NOMP,PRENOMP,NUM,ADRESSE) "
                        "VALUES (:Idp,  :Nomp, :Prenomp, :Num,:Adresse)");
          query.bindValue(":Idp", res);
          query.bindValue(":Nomp", Nomp);
          query.bindValue(":Prenomp", Prenomp);
          query.bindValue(":Num", res1);
          query.bindValue(":Adresse", Adresse);


          return  query.exec();
}
QSqlQueryModel * Parent::afficher_p()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from Parent ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Idp"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nomp"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenomp "));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Num "));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse "));

    return model;
}
bool Parent::modifier_p(int Idp, QString Nomp, QString Prenomp, int Num, QString Adresse)
{

QSqlQuery query;
QString res=QString::number(Idp);


query.prepare("update Parent set NUM =:Num ,  NOMP=:Nomp, PRENOMP=:Prenomp ,ADRESSE=:Adresse where IDP = :Idp");
query.bindValue(":Idp", res);
query.bindValue(":Nomp",Nomp );
query.bindValue(":Prenomp", Prenomp);
query.bindValue(":Num", Num);
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
