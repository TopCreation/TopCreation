#include "dialog4.h"
#include "ui_dialog4.h"
#include "enfant.h"
#include "parent.h"
#include <QMessageBox>
#include<QDateEdit>
#include <QPixmap>
#include <QMessageBox>

Dialog4::Dialog4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog4)
{
    ui->setupUi(this);
    ui->le_nomE->setInputMask("aaaaaaaaaaaaaaaaa");
    ui->le_nomP->setInputMask("aaaaaaaaaaaaaaaaa");
    ui->le_prenomE->setInputMask("aaaaaaaaaaaaaaaa");
    ui->le_prenomP->setInputMask("aaaaaaaaaaaaaaaaa");
    ui->le_idE->setValidator( new QIntValidator(0, 999999999, this) );
    ui->le_id_sup->setValidator( new QIntValidator(0, 999999999, this) );
    ui->le_idP->setValidator( new QIntValidator(0, 99999999, this) );
    ui->le_idp_sup->setValidator( new QIntValidator(0, 99999999, this) );
    ui->tabEnfant->setModel(tmpEnfant.afficher());
    ui->tabParent->setModel(tmpParent.afficher_p());
    QPixmap bkgnd("C:/users/ASUS/desktop/Atelier_Connexion/q.png");
       bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
       QPalette palette;
       palette.setBrush(QPalette::Background, bkgnd);
       this->setPalette(palette);
}

Dialog4::~Dialog4()
{
    delete ui;
}



void Dialog4::on_ajouter_enfant_clicked()
{
    int id = ui->le_idE->text().toInt();
    QString nom= ui->le_nomE->text();
    QString prenom= ui->le_prenomE->text();
    QDate dateDeNaissance= ui->la_date->date();
    QString Remarque= ui->le_remq->text();


  Enfant E (id,nom,prenom,dateDeNaissance,Remarque);

  bool test=E.ajouter();
  if(test)
{ui->tabEnfant->setModel(tmpEnfant.afficher());//refresh
QMessageBox::information(this, QObject::tr("Ajouter un enfant"),
                  QObject::tr("Enfant  ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(this, QObject::tr("Ajouter un enfant"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}


void Dialog4::on_Modifier_Enfant_clicked()
{
    int id = ui->le_idE->text().toInt();
    QString nom= ui->le_nomE->text();
    QString prenom= ui->le_prenomE->text();
    QDate dateDeNaissance= ui->la_date->date();
    QString Remarque= ui->le_remq->text();

        Enfant e;

            if(e.recherche(id)){
                bool test = e.modifier(id,nom,prenom,dateDeNaissance,Remarque);
                if(test){
                    ui->tabEnfant->setModel(tmpEnfant.afficher());
                    QMessageBox::information(this, QObject::tr("Modifier enfant"),
                                QObject::tr(" enfant modifier.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
                }
                else
                    QMessageBox::critical(this, QObject::tr("Modifier une equipements"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
            }
}



void Dialog4::on_Supprimer_Enfant_clicked()
{
    int id=ui->le_id_sup->text().toInt();
    bool test=tmpEnfant.supprimer(id);
    if(test)
    {ui->tabEnfant->setModel(tmpEnfant.afficher());//refresh
        QMessageBox::information(this, QObject::tr("Supprimer enfant"),
                    QObject::tr("enfant supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(this, QObject::tr("Supprimer un fournisseurs"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog4::on_Afficher_Enfant_clicked()
{
    ui->tabEnfant->setModel(tmpEnfant.afficher());
}
void Dialog4::on_Trier_Enfant_clicked()
{
    bool test=true;
           if(test){

                  { ui->tabEnfant->setModel(tmpEnfant.trier());
                   QMessageBox::information(this, QObject::tr("trier enfant"),
                               QObject::tr("Enfant trier.\n"
                                           "Voulez-vous enregistrer les modifications ?"),
                                      QMessageBox::Save
                                      | QMessageBox::Cancel,
                                     QMessageBox::Save);
   }

               }
               else
                   QMessageBox::critical(this, QObject::tr("trier Enfant"),
                               QObject::tr("Erreur !.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);

}

void Dialog4::on_Recherche_Enfant_clicked()
{
    int id = ui->le_id_sup->text().toInt();
      ui->tabEnfant->setModel(tmpEnfant.Recherche(id));
}

void Dialog4::on_Ajouter_Parent_clicked()
{
    int Idp = ui->le_idP->text().toInt();
    QString Nomp= ui->le_nomP->text();
    QString Prenomp= ui->le_prenomP->text();
    long Num= ui->le_num->text().toLong() ;
    QString Adresse= ui->le_add->text();


  Parent P(Idp,Nomp,Prenomp,Num,Adresse);

  bool test=P.ajouter_p();
  if(test)
{ui->tabParent->setModel(tmpParent.afficher_p());//refresh
QMessageBox::information(this, QObject::tr("Ajouter parent"),
                  QObject::tr("Parent  ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(this, QObject::tr("Ajouter parent "),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void Dialog4::on_Afficher_Parent_clicked()
{
   ui->tabParent->setModel(tmpParent.afficher_p());
}



void Dialog4::on_Modifier_Parent_clicked()
{
    int Idp = ui->le_idP->text().toInt();
    QString Nomp= ui->le_nomP->text();
    QString Prenomp= ui->le_prenomP->text();
    long Num= ui->le_num->text().toLong() ;
    QString Adresse= ui->le_add->text() ;


        Parent p ;

            if(p.Recherche_p(Idp)){
                bool test = p.modifier_p(Idp,Nomp,Prenomp,Num,Adresse);
                if(test){
                    ui->tabParent->setModel(tmpParent.afficher_p());
                    QMessageBox::information(this, QObject::tr("Modifier Parent"),
                                QObject::tr(" Parent modifier.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
                }
                else
                    QMessageBox::critical(this, QObject::tr("Modifier parent "),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
            }
}

void Dialog4::on_Supprimer_Parent_clicked()
{
    int Idp=ui->le_idp_sup->text().toInt();
    bool test=tmpParent.supprimer_p(Idp);
    if(test)
    {ui->tabParent->setModel(tmpParent.afficher_p());//refresh
        QMessageBox::information(this, QObject::tr("Supprimer parent"),
                    QObject::tr("parent supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(this, QObject::tr("Supprimer parent"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}



void Dialog4::on_OK_clicked()
{
    if( ui->radP->isChecked())
    {
        QMessageBox::information(this,"Title", ui->radP->text());
    }
    if( ui->radM->isChecked())
    {
        QMessageBox::information(this,"Title", ui->radM->text());
    }

}



void Dialog4::on_Recherche_p_clicked()
{
    int id = ui->le_idp_sup->text().toInt();
      ui->tabParent->setModel(tmpParent.Recherche_p(id));
}

void Dialog4::on_retour_clicked()
{
    hide();
}

void Dialog4::on_retour_2_clicked()
{
    hide();
}
