#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fournisseurs.h"
#include "equipements.h"
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


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->tabfournisseurs->setModel(tmpfournisseurs.afficher());//refresh
    // ui->tabequipements->setModel(tmpequipements.afficher_equipements());//refresh

    ui->le_nom->setInputMask("aaaaaaaaaaaaaaaaa");
    ui->le_prenom->setInputMask("aaaaaaaaaaaaaaaa");
   // ui->le_email->setInputMask("aaaaaaaaaaaaaaaa");
    //ui->le_adresse->setInputMask("aaaaaaaaaaaaaaaa");
    ui->le_code->setValidator( new QIntValidator(0, 999999999, this) );
    ui->le_code_2->setValidator( new QIntValidator(0, 999999999, this) );
    ui->le_code_3->setValidator( new QIntValidator(0, 999999999, this) );

    ui->le_idf->setValidator( new QIntValidator(0, 99999999, this) );
    ui->le_idf_2->setValidator( new QIntValidator(0, 99999999, this) );
    ui->le_idf_3->setValidator( new QIntValidator(0, 99999999, this) );

    ui->le_ide->setValidator( new QIntValidator(0, 99999999, this) );
    ui->le_tel->setValidator( new QIntValidator(0, 99999999, this) );
    ui->tabfournisseurs->setModel(tmpfournisseurs.afficher());
    ui->tabequipements->setModel(tmpequipements.afficher_equipements());

    QPixmap bkgnd("C:/Users/Ranim Ben Aafia/Desktop/ww.png");
       bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
       QPalette palette;
       palette.setBrush(QPalette::Background, bkgnd);
       this->setPalette(palette);


}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_fr_ajouter_clicked()
{
    int idf = ui->le_idf->text().toInt();
    long tel = ui->le_tel->text().toLong();
    QString nom= ui->le_nom->text();
    QString prenom= ui->le_prenom->text();
    QString email= ui->le_email->text();
    QString adresse= ui->le_adresse->text();

    //bool test1=(controleEmail(email)&&controleage(age));
    //if (test1)
  fournisseurs f (idf,tel,nom,prenom,email,adresse);
  bool test=f.ajouter();
  if(test)
{ui->tabfournisseurs->setModel(tmpfournisseurs.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un fournisseurs"),
                  QObject::tr("fournisseurs ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un fournisseurs"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_fr_modifier_clicked()
{
    int idf2=ui->le_idf->text().toInt();
        long tel = ui->le_tel->text().toLong();
        QString nom= ui->le_nom->text();
        QString prenom= ui->le_prenom->text();
        QString email= ui->le_email->text();
        QString adresse= ui->le_adresse->text();

       fournisseurs f1;

             bool test = f1.modifier(idf2,tel,nom,prenom,email,adresse);
                if(test){
                    ui->tabfournisseurs->setModel(tmpfournisseurs.afficher());
                    QMessageBox::information(nullptr, QObject::tr("Modifier un fournisseurs"),
                                QObject::tr(" fournisseurs modifier.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
                }
                else
                    QMessageBox::critical(nullptr, QObject::tr("Modifier un fournisseurs"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

            }


void MainWindow::on_fr_supprimer_clicked()
{
    int idf=ui->le_idf_2->text().toInt();
    bool test=tmpfournisseurs.supprimer(idf);
    if(test)
    {ui->tabfournisseurs->setModel(tmpfournisseurs.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un fournisseurs"),
                    QObject::tr("fournisseurs supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un fournisseurs"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_fr_recherche_clicked()
{
    long idf=ui->le_idf_3->text().toLong();
    ui->tabfournisseurs->setModel(tmpfournisseurs.Rechercher(idf));
}

void MainWindow::on_trierfournisseurs_clicked()
{
    bool test=true;
        if(test){

               { ui->tabfournisseurs->setModel(tmpfournisseurs.trier_idf());
                QMessageBox::information(nullptr, QObject::tr("trier patient"),
                            QObject::tr("fournisseurs trier.\n"
                                        "Voulez-vous enregistrer les modifications ?"),
                                   QMessageBox::Save
                                   | QMessageBox::Cancel,
                                  QMessageBox::Save);
}

            }
            else
                QMessageBox::critical(nullptr, QObject::tr("trier fournisseurs"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);




}



void MainWindow::on_pb_ajouter_p_clicked()
{
    int code = ui->le_code->text().toInt();
    int ide = ui->le_ide->text().toInt();

    QDate date_creation= ui->le_date->date();
 equipements eq(code,ide,date_creation);
  bool test=eq.ajouter_equipements();
  if(test)
{ui->tabequipements->setModel(tmpequipements.afficher_equipements());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une equipements"),
                  QObject::tr("equipements ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une equipements"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_modifier_p_clicked()
{
    int code2=ui->le_code->text().toInt();
    int le_ide=ui->le_ide->text().toInt();
    QDate date_delivration= ui->le_date->date();

        equipements eq;

            if(eq.rech(code2)){
                bool test = eq.modifier(le_ide,code2,date_delivration);
                if(test){
                    ui->tabequipements->setModel(tmpequipements.afficher_equipements());
                    QMessageBox::information(nullptr, QObject::tr("Modifier une equipements"),
                                QObject::tr(" equipements modifier.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
                }
                else
                    QMessageBox::critical(nullptr, QObject::tr("Modifier une equipements"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
            }
}

void MainWindow::on_pb_supprimer_p_clicked()
{
    int idf=ui->le_idf_2->text().toInt();
    bool test=tmpfournisseurs.supprimer(idf);
    if(test)
    {ui->tabfournisseurs->setModel(tmpfournisseurs.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un fournisseurs"),
                    QObject::tr("fournisseurs supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un fournisseurs"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pb_recherche_p_clicked()
{
    long idf=ui->le_code_3->text().toLong();
    ui->tabequipements->setModel(tmpequipements.Rechercher(idf));
}

void MainWindow::on_trie_poste_clicked()
{
    bool test=true;

        if(test){
                {ui->tabequipements->setModel(tmpequipements.trierequipements_code());
                QMessageBox::information(nullptr, QObject::tr("trier equipements"),
                            QObject::tr("equipements triée.\n"
                                        "Voulez-vous enregistrer les modifications ?"),
                                   QMessageBox::Save
                                   | QMessageBox::Cancel,
                                  QMessageBox::Save);}
}
}



void MainWindow::on_sendBtn_2_clicked()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toUShort());
            connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


            smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
       QString status;
            if(status == "Message sent")
                QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );

}

void MainWindow::on_Imprimer_clicked()
{

        QString strStream;
                    QTextStream out(&strStream);

                    const int rowCount = ui->tabfournisseurs->model()->rowCount();
                    const int columnCount = ui->tabfournisseurs->model()->columnCount();
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
                        if (!ui->tabfournisseurs->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->tabfournisseurs->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";

                    // data table
                    for (int row = 0; row < rowCount; row++) {
                        out << "<tr>";
                        for (int column = 0; column < columnCount; column++) {
                            if (!ui->tabfournisseurs->isColumnHidden(column)) {
                                QString data =ui->tabfournisseurs->model()->data(ui->tabfournisseurs->model()->index(row, column)).toString().simplified();
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






void MainWindow::on_tabfournisseurs_activated(const QModelIndex &index)
{
    QString val=ui->tabfournisseurs->model()->data(index).toString();
     QSqlQuery query;

     query.prepare("select * from FOURNISSEURS where IDF='"+val+"'");
     if(query.exec())
     {
         while (query.next())
         {

             ui->le_idf->setText(query.value(0).toString());
             ui->le_nom->setText(query.value(2).toString());
             ui->le_prenom->setText(query.value(3).toString());
             ui->le_adresse->setText(query.value(5).toString());
             ui->le_email->setText(query.value(4).toString());
             ui->le_tel->setText(query.value(1).toString());



        }
     }

}

void MainWindow::on_tabequipements_activated(const QModelIndex &index)
{
    QString val=ui->tabequipements->model()->data(index).toString();
     QSqlQuery query;

     query.prepare("select * from equipements where code='"+val+"'");
     if(query.exec())
     {
         while (query.next())
         {

             ui->le_code->setText(query.value(0).toString());
             ui->le_ide->setText(query.value(1).toString());
             ui->le_date->setDate(query.value(2).toDate());


        }
     }
}
