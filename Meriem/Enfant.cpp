#include "Enfant.h"
#include<QSqlQuery>
#include<QString>
#include<QDate>
#include<QVariant>
#include<QComboBox>




Enfant::Enfant()
{

}

Enfant::Enfant(int id,QString nom,QString prenom,QDate dateDeNaissance,QString Remarque)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->dateDeNaissance=dateDeNaissance;
    this->Remarque=Remarque;


}

bool Enfant::ajouter()
{
    QSqlQuery query;

      QString res=QString::number(id);


            query.prepare("INSERT INTO enfant (id,nom,prenom,dateDeNaissance,Remarque) "
                          "VALUES (:id,  :nom, :prenom, :dateDeNaissance,:Remarque)");
            query.bindValue(":id", res);
            query.bindValue(":nom", nom);
            query.bindValue(":prenom", prenom);
            query.bindValue(":dateDeNaissance", dateDeNaissance);
            query.bindValue(":Remarque", Remarque);



            return  query.exec();
}

QSqlQueryModel * Enfant::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from Enfant ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom "));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DateDeNaisance "));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Remarque "));

    return model;
}

bool Enfant::supprimer(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from Enfant where id = :id ");
query.bindValue(":id", res);
return    query.exec();
}

/*bool Enfant::recherche(int id){
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("select * from Enfant where id = :id");
    query.bindValue(":id", res);
    return query.exec();
}*/

bool Enfant::modifier(int id,QString nom,QString prenom,QDate dateDeNaissance,QString Remarque)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("update Enfant set dateDeNaissance =:dateDeNaissance ,nom=:nom,prenom=:prenom,Remarque=:Remarque where id = :id");
    query.bindValue(":id", res);
    query.bindValue(":dateDeNaissance", dateDeNaissance);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":Remarque", Remarque);
    return query.exec();
}


QSqlQueryModel *  Enfant::trier()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from  Enfant ORDER BY id");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DateDeNaisance "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Remarque "));
        return model;
}



QSqlQueryModel *  Enfant::afficher(int id)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    QString res=QString::number(id);
    model->setQuery("select id,nom,prenom,dateDeNaissance,Remarque from Enfant WHERE regexp_like(id,:id)");
    query.bindValue(":id", res);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("dateDeNaissance"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Remarque"));

        return model;
}


QSqlQueryModel *  Enfant::Recherche(int id)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString res=QString::number(id);
    model->setQuery("select * from Enfant where (id LIKE '"+res+"%' ) ");

            return  model;


}

