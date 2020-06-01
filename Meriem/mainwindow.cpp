#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Enfant.h"
#include "parent.h"
#include <QMessageBox>
#include<QDate>
#include<QDateEdit>
#include <QPixmap>
#include <QMessageBox>
#include <QPainter>
#include <QPdfWriter>
#include <QPrintPreviewDialog>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
#define CARACTERES_ETRANGERS "~{}[]()|-`'^ç@_]\"°01234567890+=£$*µ/§!?,.&#;><"
#include<QTextDocument>
#include<QTextStream>





MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
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
    QPixmap pix("C:/Users/RIB/Desktop/interface2/www.png");
    ui->le_pic->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio)) ;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ajouter_enfant_clicked()
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
QMessageBox::information(nullptr, QObject::tr("Ajouter un enfant"),
                  QObject::tr("Enfant  ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un enfant"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_Modifier_Enfant_clicked()
{
    int id = ui->le_idE->text().toInt();
    QString nom= ui->le_nomE->text();
    QString prenom= ui->le_prenomE->text();
    QDate dateDeNaissance= ui->la_date->date();
    QString Remarque= ui->le_remq->text();

        Enfant e;

            if(e.Recherche(id)){
                bool test = e.modifier(id,nom,prenom,dateDeNaissance,Remarque);
                if(test){
                    ui->tabEnfant->setModel(tmpEnfant.afficher());
                    QMessageBox::information(nullptr, QObject::tr("Modifier enfant"),
                                QObject::tr(" enfant modifier.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
                }
                else
                    QMessageBox::critical(nullptr, QObject::tr("Modifier une equipements"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
            }
}



void MainWindow::on_Supprimer_Enfant_clicked()
{
    int id=ui->le_id_sup->text().toInt();
    bool test=tmpEnfant.supprimer(id);
    if(test)
    {ui->tabEnfant->setModel(tmpEnfant.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer enfant"),
                    QObject::tr("enfant supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un fournisseurs"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_Trier_Enfant_clicked()
{
    bool test=true;
           if(test){

                  { ui->tabEnfant->setModel(tmpEnfant.trier());
                   QMessageBox::information(nullptr, QObject::tr("trier enfant"),
                               QObject::tr("Enfant trier.\n"
                                           "Voulez-vous enregistrer les modifications ?"),
                                      QMessageBox::Save
                                      | QMessageBox::Cancel,
                                     QMessageBox::Save);
   }

               }
               else
                   QMessageBox::critical(nullptr, QObject::tr("trier Enfant"),
                               QObject::tr("Erreur !.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_Recherche_Enfant_clicked()
{
    int id = ui->le_idE->text().toInt();
      ui->tabEnfant->setModel(tmpEnfant.Recherche(id));
}

void MainWindow::on_Ajouter_Parent_clicked()
{
    int Idp = ui->le_idP->text().toInt();
    QString Nom_p= ui->le_nomP->text();
    QString Prenom_p= ui->le_prenomE->text();
    long Num = ui->le_num->text().toLong();

    QString Adresse= ui->le_add->text();


  Parent P (Idp,Nom_p,Prenom_p,Num,Adresse);

  bool test=P.ajouter_p();
  if(test)

{ui->tabParent->setModel(tmpParent.afficher_p());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un parent"),
                  QObject::tr("Parent  ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un parent"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_Modif_p_clicked()
{
    int Idp = ui->le_idP->text().toInt();
    QString Nom_p= ui->le_nomP->text();
    QString Prenom_p= ui->le_prenomP->text();
    long Num= ui->le_num->text().toLong() ;
    QString Adresse= ui->le_add->text() ;


        Parent p ;


                bool test = p.modifier_p(Idp,Nom_p,Prenom_p,Num,Adresse);
                if(test){
                    ui->tabParent->setModel(tmpParent.afficher_p());
                    QMessageBox::information(nullptr, QObject::tr("Modifier Parent"),
                                QObject::tr(" Parent modifier.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
                }
                else
                    QMessageBox::critical(nullptr, QObject::tr("Modifier parent "),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_Sup_p_clicked()
{
    int Idp=ui->le_idp_sup->text().toInt();
    bool test=tmpParent.supprimer_p(Idp);
    if(test)
    {ui->tabParent->setModel(tmpParent.afficher_p());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer parent"),
                    QObject::tr("parent supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un parent"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_OK_clicked()
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



void MainWindow::on_Recherche_p_clicked()
{
    int Idp = ui->le_idP->text().toInt();
      ui->tabParent->setModel(tmpParent.Recherche_p(Idp));
}

void MainWindow::on_tabParent_activated(const QModelIndex &index)
{

    QString val=ui->tabParent->model()->data(index).toString();
    QSqlQuery query;

    query.prepare("select * from Parent where Idp='"+val+"'");
    if(query.exec())
    {
        while (query.next())
        {

            ui->le_idP->setText(query.value(0).toString());
            ui->le_nomP->setText(query.value(1).toString());
            ui->le_prenomP->setText(query.value(2).toString());
            ui->le_num->setText(query.value(3).toString());
            ui->le_add->setText(query.value(4).toString());




       }
    }

}



void MainWindow::on_tabEnfant_activated(const QModelIndex &index)
{

    QString val=ui->tabEnfant->model()->data(index).toString();
    QSqlQuery query;

    query.prepare("select * from Enfant where ID='"+val+"'");
    if(query.exec())
    {
        while (query.next())
        {

            ui->le_idE->setText(query.value(0).toString());
            ui->le_nomE->setText(query.value(1).toString());
            ui->le_prenomE->setText(query.value(2).toString());
            ui->la_date->setDate(query.value(3).toDate());
            ui->le_remq->setText(query.value(4).toString());




       }
    }
}

/*void MainWindow::on_le_pic_linkActivated(const QString &link)
{

}*/

void MainWindow::on_Iprim_clicked()
{



        }




