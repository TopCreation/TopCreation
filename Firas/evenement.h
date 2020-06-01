#ifndef EVENEMENT_H
#define EVENEMENT_H
#include<QString>
#include<QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Event
{
    int idev,frais_ev;
     QDate date_ev;
     QString nom_ev;
public:
    Event();
    Event(int,int,QDate,QString);
    int getidev() ;
    int getfrais_ev(){return frais_ev;}
    QString getnom_ev(){return nom_ev;}
    void setidev(int idev){this->idev=idev;}
    void setfrais_ev(int frais_ev){this->frais_ev=frais_ev;}
    void setdate_date_ev(QDate date_ev){this->date_ev=date_ev;}
    void setnom_ev(QString nom_ev){this->nom_ev=nom_ev;}
    bool ajouter_event();
    QSqlQueryModel * afficher_event();
    bool supprimer_event(int);
    bool rech(int);
    bool modifier(int,int,QDate,QString);
        QSqlQueryModel * afficher_event_ch(int);
        QSqlQueryModel * trierevent_frais_ev();
        QSqlQueryModel * Rechercher_event(int);

       // bool  rech_event(int id);


    ~Event(){}

};

#endif // EVENEMENT_H
