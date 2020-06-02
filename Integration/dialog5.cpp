#include "dialog5.h"
#include "ui_dialog5.h"
#include "activity.h"
#include "evenement.h"
#include "smtp.h"
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

Dialog5::Dialog5(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog5)
{
    ui->setupUi(this);
    ui->tab_ev->setModel(tmpev.afficher_event());
    ui->tab_ac->setModel(tmpac.afficher_activity());

    QPixmap bkgnd("C:/users/ASUS/desktop/Atelier_Connexion/q.png");
       bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
       QPalette palette;
       palette.setBrush(QPalette::Background, bkgnd);
       this->setPalette(palette);


}

Dialog5::~Dialog5()
{
    delete ui;
}



void Dialog5::on_ajouter_ac_clicked()
{

        int idac = ui->idac->text().toInt();
        int cap_ac = ui->cap_ac->text().toInt();
        QString nom_ac=ui->nom_ac->text();
        QDate date_ac= ui->date_ac->date();
     Activity eq(idac,cap_ac,date_ac,nom_ac);
      bool test=eq.ajouter_activity();
      if(test)
    {ui->tab_ac->setModel(tmpac.afficher_activity());//refresh
    QMessageBox::information(this, QObject::tr("Ajouter une activité"),
                      QObject::tr("activité ajoutée.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(this, QObject::tr("Ajouter une activité"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

}

void Dialog5::on_modifier_ac_clicked()
{

    int idac=ui->idac->text().toInt();
        int cap_ac = ui->cap_ac->text().toInt();
          QDate date_ac= ui->date_ac->date();
        QString nom_ac= ui->nom_ac->text();



       Activity a1;

             bool test = a1.modifier(idac,cap_ac,date_ac,nom_ac);
                if(test){
                    ui->tab_ac->setModel(tmpac.afficher_activity());
                    QMessageBox::information(this, QObject::tr("Modifier un activité"),
                                QObject::tr(" activité modifiée .\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
                }
                else
                    QMessageBox::critical(this, QObject::tr("Modifier une activité"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

}
    void Dialog5::on_fr_supprimer_ac_clicked() //int idac,int cap_ac,QDate date_ac,QString nom_ac
    {
        int idac=ui->idac_3->text().toInt();
        bool test=tmpac.supprimer_activity(idac);
        if(test)
        {ui->tab_ac->setModel(tmpac.afficher_activity());//refresh
            QMessageBox::information(this, QObject::tr("Supprimer une activité"),
                        QObject::tr("activité supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(this, QObject::tr("Supprimer une activité"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }

    void Dialog5::on_fr_recherche_ac_clicked() //int idac,int cap_ac,QDate date_ac,QString nom_ac
    {
        long idac=ui->idac_2->text().toLong();
        ui->tab_ac->setModel(tmpac.Rechercher_activity(idac));
    }

    void Dialog5::on_trier_ac_clicked()
    {
        bool test=true;
            if(test){

                   { ui->tab_ac->setModel(tmpac.trieractivity_cap_ac());
                    QMessageBox::information(this, QObject::tr("trier capacité"),
                                QObject::tr("activité triée.\n"
                                            "Voulez-vous enregistrer les modifications ?"),
                                       QMessageBox::Save
                                       | QMessageBox::Cancel,
                                      QMessageBox::Save);
    }

                }
                else
                    QMessageBox::critical(this, QObject::tr("trier activité"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);




    }



    void Dialog5::on_pb_ajouter_ev_clicked()
    {
            int idev = ui->idev->text().toInt();
            int frais_ev = ui->fr_ev->text().toInt();
        QDate date_ev= ui->date_ev->date();
        QString nom_ev=ui->nom_ev->text();
     Event ev(frais_ev,idev,date_ev,nom_ev);
      bool test=ev.ajouter_event();
      if(test)
    {ui->tab_ev->setModel(tmpev.afficher_event());//refresh
    QMessageBox::information(this, QObject::tr("Ajouter un evenement"),
                      QObject::tr("evenement ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(this, QObject::tr("Ajouter un evenement"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
    }

    void Dialog5::on_pb_modifier_ev_clicked() //int idev,int frais_ev,QDate date_ev,QString nom_ev
    {
        int idev=ui->idev_2->text().toInt();
        int frais_ev=ui->fr_ev->text().toInt();
        QDate date_ev= ui->date_ev->date();
    QString nom_ev=ui->nom_ev->text();
            Event ev;

                if(ev.rech(idev)){
                    bool test = ev.modifier(frais_ev,idev,date_ev,nom_ev);
                    if(test){
                        ui->tab_ev->setModel(tmpev.afficher_event());
                        QMessageBox::information(this, QObject::tr("Modifier un evenement"),
                                    QObject::tr(" events modifier.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
                    }
                    else
                        QMessageBox::critical(this, QObject::tr("Modifier un evenement"),
                                    QObject::tr("Erreur !.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
                }
    }

    void Dialog5::on_pb_supprimer_ev_clicked()
    {
        int idev=ui->idev_2->text().toInt();
        bool test=tmpev.supprimer_event(idev);
        if(test)
        {ui->tab_ev->setModel(tmpev.afficher_event());//refresh
            QMessageBox::information(this, QObject::tr("Supprimer un evenement"),
                        QObject::tr("fournisseurs supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(this, QObject::tr("Supprimer un evenement"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }

    void Dialog5::on_pb_recherche_ev_clicked()
    {
        long idev=ui->idev_1->text().toLong();
        ui->tab_ev->setModel(tmpev.Rechercher_event(idev));
    }

    void Dialog5::on_trier_ev_clicked()
    {
        bool test=true;

            if(test){
                    {ui->tab_ev->setModel(tmpev.trierevent_frais_ev());
                    QMessageBox::information(this, QObject::tr("trier evenement"),
                                QObject::tr("equipements triée.\n"
                                            "Voulez-vous enregistrer les modifications ?"),
                                       QMessageBox::Save
                                       | QMessageBox::Cancel,
                                      QMessageBox::Save);}
    }
    }


    void Dialog5::on_Imprimer_ac_clicked()
    {

            QString strStream;
                        QTextStream out(&strStream);

                        const int rowCount = ui->tab_ac->model()->rowCount();
                        const int columnCount = ui->tab_ac->model()->columnCount();
                        QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                        out <<"<html>\n"
                              "<head>\n"
                               "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                            << "<title>ERP - COMmANDE LIST<title>\n "
                            << "</head>\n"
                            "<body bgcolor=#ffffff link=#5000A0>\n"
                            "<h1 style=\"text-align: center;\"><strong> ******LISTE DES Employer ****** "+TT+"</strong></h1>"
                            "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                              "</br> </br>";
                        // headers
                        out << "<thead><tr bgcolor=#d6e5ff>";
                        for (int column = 0; column < columnCount; column++)
                            if (!ui->tab_ac->isColumnHidden(column))
                                out << QString("<th>%1</th>").arg(ui->tab_ac->model()->headerData(column, Qt::Horizontal).toString());
                        out << "</tr></thead>\n";

                        // data table
                        for (int row = 0; row < rowCount; row++) {
                            out << "<tr>";
                            for (int column = 0; column < columnCount; column++) {
                                if (!ui->tab_ac->isColumnHidden(column)) {
                                    QString data =ui->tab_ac->model()->data(ui->tab_ac->model()->index(row, column)).toString().simplified();
                                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                }
                            }
                            out << "</tr>\n";
                        }
                        out <<  "</table>\n"
                            "</body>\n"
                            "</html>\n";

                        QTextDocument *document = new QTextDocument();
                        document->setHtml(strStream);

                        QPrinter printer;

                        QPrintDialog *dialog = new QPrintDialog(&printer, this);
                        if (dialog->exec() == QDialog::Accepted) {
                            document->print(&printer);
                        }

                        delete document;
        }











void Dialog5::on_retour_clicked()
{
    hide();
}

void Dialog5::on_retour_2_clicked()
{
     hide();
}

void Dialog5::on_retour2_2_clicked()
{
     hide();
}


