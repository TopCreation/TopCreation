//#include "smtp.h"
#include "employe.h"
#include <QDebug>
//#include "connetion.h"
#include<QSqlQuery>
#include<QString>
#include<QDate>
#include<QVariant>
Employe::Employe()
{
id=0;
nom="";
prenom="";
age=0;
email="";
nom_poste="";
image="";
}
Employe::Employe(int id,QString nom,QString prenom,int age,QString email ,QDate datec,QDate datee,QString nom_poste,QString image)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
  this->age=age;
 this->email=email;
    this->datec=datec;
     this->datee=datee;
    this->nom_poste=nom_poste;
     this->image=image;

}
QString Employe::get_nom(){return  nom;}
QString Employe::get_prenom(){return prenom;}
int Employe::get_id(){return  id;}
int Employe::get_age(){return  age;}
QDate Employe::get_datec(){return datec;}
QDate Employe::get_datee(){return datee;}
QString Employe::get_email(){return email;}
QString Employe::get_nom_poste(){return nom_poste;}
void Employe::set_id(int id){this->id=id;}
QString Employe::get_image(){return image;}
void Employe::set_image(QString(image)){this->image=image;}

QSqlQueryModel * Employe::afficher_nom()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select nom_poste from Poste");
    return model;
}


bool Employe::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO Employe (ID, NOM, PRENOM, AGE, EMAIL, DATEC, DATEE , NOM_POSTE , IMAGE) "
                    "VALUES (:id, :nom, :prenom, :age, :email, :datec ,:datee, :nom_poste, :image)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":age", age);
query.bindValue(":email", email);
query.bindValue(":datec", datec);
query.bindValue(":datee", datee);
query.bindValue(":nom_poste", nom_poste);
query.bindValue(":image", image);

return    query.exec();
}



QSqlQueryModel * Employe::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from Employe");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Age"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("datec"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("datee"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("poste"));
model->setHeaderData(8, Qt::Horizontal, QObject::tr("image"));
    return model;
}

bool Employe::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from Employe where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

bool Employe::modifier(int idd,QString nom,QString prenom,int age,QString email,QDate datec,QDate datee, QString nom_poste,QString image)
{ QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("UPDATE Employe SET NOM=:nom,PRENOM=:prenom, AGE=:age, EMAIL=:email, DATEC=:datec, DATEE=:datee, NOM_POSTE=:nom_poste ,IMAGE=:image  where ID=:id");
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
     query.bindValue(":age",age);
     query.bindValue(":email",email);
     query.bindValue(":datec", datec);
     query.bindValue(":datee", datee);
     query.bindValue(":nom_poste", nom_poste);
      query.bindValue(":image", image);


    return query.exec();

}
QSqlQueryModel *  Employe::Rechercher(QString  prenom)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString res=QString(prenom);
    model->setQuery("select * from Employe where (prenom LIKE '"+res+"%' ) ");


            return  model;


}
QSqlQueryModel * Employe::trier_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from Employe ORDER BY id");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Age"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("datec"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("datee"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("poste"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("image"));

        return model;
}

