#include "activity.h"
#include<QSqlQuery>
#include<QString>
#include<QDate>
#include<QVariant>


Activity::Activity()
{   idac= 0 ;
    cap_ac=0;
    nom_ac = "";

}


Activity::Activity(int idac,int cap_ac,QDate date_ac,QString nom_ac)
{
    this->idac=idac;
    this->cap_ac=cap_ac;
    this->date_ac=date_ac;
    this->nom_ac=nom_ac;
}

bool Activity::ajouter_activity()
{
    QSqlQuery query;
    QString res=QString::number(idac);
    QString res1=QString::number(cap_ac);

          query.prepare("INSERT INTO ACTIVITY (idac,cap_ac,date_ac,nom_ac) "
                        "VALUES (:idac, :cap_ac, :date_ac, :nom_ac)");
          query.bindValue(":idac", res);
          query.bindValue(":cap_ac", res1);
          query.bindValue(":date_ac", date_ac);
          query.bindValue(":nom_ac",nom_ac);


          return  query.exec();
}

QSqlQueryModel * Activity::afficher_activity()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from ACTIVITY ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("idac"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("cap_ac "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_ac "));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom_ac "));
    return model;
}

bool Activity::supprimer_activity(int idac)
{
QSqlQuery query;
QString res= QString::number(idac);
query.prepare("Delete from ACTIVITY where idac = :idac ");
query.bindValue(":idac", res);
return    query.exec();
}

bool Activity::rech(int idac){
    QSqlQuery query;
    QString res=QString::number(idac);
    query.prepare("select * from ACTIVITY where idac = :idac");
    query.bindValue(":idac", res);
    return query.exec();
}

bool Activity::modifier(int idac,int cap_ac,QDate date_ac,QString nom_ac){
    QSqlQuery query;
    QString res=QString::number(idac);
    query.prepare("update ACTIVITY set date_ac=:date_ac where idac = :idac");
    query.prepare("update ACTIVITY set cap_ac=:cap_ac where idac = :idac");
    query.prepare("update ACTIVITY set nom_ac=:nom_ac where idac = :idac");
    query.bindValue(":idac", res);
    query.bindValue(":date_ac", date_ac);
    query.bindValue(":cap_ac", cap_ac);
    query.bindValue(":nom_ac", nom_ac);


    return query.exec();
}


QSqlQueryModel *  Activity::trieractivity_cap_ac()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from  ACTIVITY ORDER BY cap_ac");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cap_ac"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("idac"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_ac"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom_ac"));
        return model;
}



QSqlQueryModel *  Activity::afficher_activity_ch(int cap_ac)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    QString res=QString::number(cap_ac);
    model->setQuery("select idac,cap_ac,date_ac,nom_ac from ACTIVITY WHERE regexp_like(cap_ac,:cap_ac)");
    query.bindValue(":cap_ac", res);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cap_ac"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("idac"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_ac"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom_ac"));

        return model;
}


QSqlQueryModel *  Activity::Rechercher_activity(int idac)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString res=QString::number(idac);
    model->setQuery("select * from ACTIVITY where (idac LIKE '"+res+"%' ) ");


            return  model;
}



