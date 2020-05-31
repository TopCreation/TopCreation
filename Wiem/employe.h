#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QDialog>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QDate>
//#include "smtp.h"


class Employe
{
public:
    Employe();
    Employe(int,QString,QString,int,QString,QDate,QDate,QString,QString);
    QString get_nom();
     QString get_image();
    QString get_prenom();
    int get_age();
    QString get_email();
    QDate get_datec();
    QDate get_datee();
    int get_id();
    QString get_nom_poste();
    void set_id(int ID);
     void set_image(QString);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
     bool modifier(int, QString ,QString,int,QString,QDate,QDate,QString,QString);
  QSqlQueryModel * Rechercher(QString );
  QSqlQueryModel * trier_id();
  QSqlQueryModel * afficher_nom();
  void sendMail();
  void mailSent(QString status);


private:
    QString nom,prenom,nom_poste,image;
   QString email;
    int id, age;
    QDate datec, datee;
};

#endif // EMPLOYE_H
