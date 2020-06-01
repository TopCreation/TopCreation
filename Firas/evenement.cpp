#include "evenement.h"
#include<QSqlQuery>
#include<QString>
#include<QDate>
#include<QVariant>


Event::Event()
{   idev= 0 ;
    frais_ev=0;
    nom_ev = "";

}


Event::Event(int idev,int frais_ev,QDate date_ev,QString nom_ev)
{
    this->idev=idev;
    this->frais_ev=frais_ev;
    this->date_ev=date_ev;
    this->nom_ev=nom_ev;
}

bool Event::ajouter_event()
{
    QSqlQuery query;
    QString res=QString::number(idev);
    QString res1=QString::number(frais_ev);

          query.prepare("INSERT INTO EVENEMENT (idev,frais_ev,date_ev,nom_ev) "
                        "VALUES (:idev,:frais_ev, :date_ev,nom_ev)");
          query.bindValue(":idev", res);
          query.bindValue(":frais_ev", res1);
          query.bindValue(":date_ev", date_ev);
          query.bindValue(":nom_ev",nom_ev);


          return  query.exec();
}

QSqlQueryModel * Event::afficher_event()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from EVENEMENT ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("idev"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("frais_ev "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_ev "));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom_ev "));
    return model;
}

bool Event::supprimer_event(int idev)
{
QSqlQuery query;
QString res= QString::number(idev);
query.prepare("Delete from EVENEMENT where idev = :idev ");
query.bindValue(":idev", res);
return    query.exec();
}

bool Event::rech(int idev){
    QSqlQuery query;
    QString res=QString::number(idev);
    query.prepare("select * from EVENEMENT where idev = :idev");
    query.bindValue(":idev", res);
    return query.exec();
}

bool Event::modifier(int idev,int frais_ev,QDate date_ev,QString nom_ev){
    QSqlQuery query;
    QString res=QString::number(idev);
    query.prepare("update EVENEMENT set date_ev=:date_ev where idev = :idev");
    query.prepare("update EVENEMENT set frais_ev=:frais_ev where idev = :idev");
    query.prepare("update EVENEMENT set nom_ev=:nom_ev where idev = :idev");
    query.bindValue(":idev", res);
    query.bindValue(":date_ev", date_ev);
    query.bindValue(":frais_ev", frais_ev);
    query.bindValue(":nom_ev", nom_ev);
    return query.exec();
}


QSqlQueryModel *  Event::trierevent_frais_ev()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from  EVENEMENT ORDER BY frais_ev");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("frais_ev"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("idev"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_ev"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom_ev"));
        return model;
}



QSqlQueryModel *  Event::afficher_event_ch(int frais_ev)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    QString res=QString::number(frais_ev);
    model->setQuery("select idev,frais_ev,date_ev,nom_ev from EVENEMENT WHERE regexp_like(frais_ev,:frais_ev)");
    query.bindValue(":frais_ev", res);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("frais_ev"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("idev"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_ev"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom_ev"));

        return model;
}


QSqlQueryModel *  Event::Rechercher_event(int idev)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString res=QString::number(idev);
    model->setQuery("select * from EVENEMENT where (idev LIKE '"+res+"%' ) ");


            return  model;
}


