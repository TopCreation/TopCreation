#include "equipements.h"
#include<QSqlQuery>
#include<QString>
#include<QDate>
#include<QVariant>


equipements::equipements()
{
    code=0;

}


equipements::equipements(int code,int ide,QDate date_delivration)
{
    this->code=code;
    this->ide=ide;
    this->date_delivration=date_delivration;
}

bool equipements::ajouter_equipements()
{
    QSqlQuery query;
    QString res=QString::number(code);
    QString res1=QString::number(ide);

          query.prepare("INSERT INTO equipements (code,ide,date_delivration) "
                        "VALUES (:code,:ide, :date_delivration)");
          query.bindValue(":code", res);
          query.bindValue(":ide", res1);
          query.bindValue(":date_delivration", date_delivration);


          return  query.exec();
}

QSqlQueryModel * equipements::afficher_equipements()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from equipements ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Code"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ide "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date_delivration "));
    return model;
}

bool equipements::supprimer_equipements(int code1)
{
QSqlQuery query;
QString res= QString::number(code1);
query.prepare("Delete from equipements where code = :code ");
query.bindValue(":code", res);
return    query.exec();
}

bool equipements::rech(int code){
    QSqlQuery query;
    QString res=QString::number(code);
    query.prepare("select * from equipements where code = :code");
    query.bindValue(":code", res);
    return query.exec();
}

bool equipements::modifier(int ide,int code,QDate date_delivration){
    QSqlQuery query;
    QString res=QString::number(ide);
    query.prepare("update equipements set date_delivration=:date_delivration where ide = :ide");
    query.prepare("update equipements set code=:code where ide = :ide");
    query.bindValue(":ide", res);
    query.bindValue(":date_delivration", date_delivration);
    query.bindValue(":code", code);

    return query.exec();
}


QSqlQueryModel *  equipements::trierequipements_code()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from  equipements ORDER BY Code");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Code"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ide"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date_delivration"));
        return model;
}



QSqlQueryModel *  equipements::afficher_equipements_ch(int code)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    QString res=QString::number(code);
    model->setQuery("select Code,ide,Date_delivration from equipements WHERE regexp_like(Code,:code)");
    query.bindValue(":code", res);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Code"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ide"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date_delivration"));
        return model;
}

/*bool  equipements::rech_equipements(int code){
    QSqlQuery query;
    QString res=QString::number(code);
    query.prepare("select * from  equipements where regexp_like(Code,:code)");
    query.bindValue(":code", res);

    return query.exec();
}*/
QSqlQueryModel *  equipements::Rechercher(int code)
{

        QSqlQueryModel * model=new QSqlQueryModel();
        QString res=QString::number(code);
        model->setQuery("select * from equipements where (code LIKE '"+res+"%' ) ");


                return  model;


}

