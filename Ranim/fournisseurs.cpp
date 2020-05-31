#include "fournisseurs.h"
#include<QSqlQuery>
#include<QString>
#include<QVariant>

fournisseurs::fournisseurs()
{
    idf=0;
    tel=00;
    nom="";
    prenom="";
    email="";
}

fournisseurs::fournisseurs(int idf,long tel,QString nom,QString prenom,QString email,QString adresse)
{
this->idf=idf;
this->tel=tel;
this->nom=nom;
this->prenom=prenom;
this->email=email;
this->adresse=adresse;
}

bool fournisseurs::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(idf);
    QString res1=QString::number(tel);
          query.prepare("INSERT INTO fournisseurs (idf,tel, nom, prenom,email,adresse) "
                        "VALUES (:idf, :tel, :nom, :prenom, :email,:adresse)");
          query.bindValue(":idf", res);
          query.bindValue(":tel", res1);
          query.bindValue(":nom", nom);
          query.bindValue(":prenom", prenom);
          query.bindValue(":email", email);
          query.bindValue(":adresse", adresse);

          return  query.exec();
}

QSqlQueryModel * fournisseurs::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from fournisseurs");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("idf"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Telephone"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("email"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse"));
    return model;
}

bool fournisseurs::supprimer(long idf)
{
QSqlQuery query;
QString res= QString::number(idf);
query.prepare("Delete from fournisseurs where idf = :idf ");
query.bindValue(":idf", res);
return    query.exec();
}


bool fournisseurs::modifier(int idf,long tel,QString nom,QString prenom,QString email,QString adresse){
    QSqlQuery query;
    QString res=QString::number(idf);
    QString res1=QString::number(tel);
    query.prepare("update fournisseurs set tel=:tel ,nom=:nom ,prenom=:prenom ,email=:email ,adresse=:adresse where idf = :idf");
    query.bindValue(":idf", res);
    query.bindValue(":tel", res1);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":email", email);
    query.bindValue(":adresse", adresse);
    return query.exec();
}

bool fournisseurs::rech(long idf){
    QSqlQuery query;
    QString res=QString::number(idf);
    QString res1=QString::number(tel);
    query.prepare("select * from fournisseurs where idf = :idf");
    query.bindValue(":idf", res);
    query.bindValue(":tel", res1);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":email", email);
    query.bindValue(":adresse", adresse);
    return query.exec();
}

QSqlQueryModel * fournisseurs::afficherfournisseurschercher(int idf)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString res=QString::number(idf);
    model->setQuery("select * from fournisseurs where idf= :idf");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idf"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Telephone"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("email"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("adresse"));


    return model;
}

QSqlQueryModel * fournisseurs::trier_idf()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from fournisseurs ORDER BY idf");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idf"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Telephone"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("email"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("adresse"));

    return model;
}




QSqlQueryModel *  fournisseurs::Rechercher(int idf)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString res=QString::number(idf);
    model->setQuery("select * from fournisseurs where (idf LIKE '"+res+"%' ) ");


            return  model;
}


