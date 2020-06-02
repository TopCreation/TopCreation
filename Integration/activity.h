#ifndef ACTIVITY_H
#define ACTIVITY_H


#include<QString>
#include<QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Activity
{
    int idac,cap_ac;
     QDate date_ac;
     QString nom_ac;
public:
    Activity();
    Activity(int,int,QDate,QString);
    int getidcap() ;
    int getcap_ac(){return cap_ac;}
    QString getnom_ac() ;
    void setidac(int idac){this->idac=idac;}
    void setcap_ac(int cap_ac){this->cap_ac=cap_ac;}
    void setdate_date_ac(QDate date_ac){this->date_ac=date_ac;}
    bool ajouter_activity();
    QSqlQueryModel * afficher_activity();
    bool supprimer_activity(int);
    bool rech(int);
    bool modifier(int,int,QDate,QString);
        QSqlQueryModel * afficher_activity_ch(int);
        QSqlQueryModel * trieractivity_cap_ac();
        QSqlQueryModel * Rechercher_activity(int);

       // bool  rech_activity(int id);


    ~Activity(){}

};

#endif // ACTIVITY_H
