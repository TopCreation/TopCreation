#include "secdialog.h"
#include "ui_secdialog.h"
#include "employe.h"
#include "poste.h"
#include <QDebug>
#include <QPrinter>
#include <QPainter>
#include <QMessageBox>
#include <QFileDialog>
#include <QDate>
#include <QPrintPreviewDialog>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
#define CARACTERES_ETRANGERS "~{}[]()|-`'^ç@_]\"°01234567890+=£$*µ/§!?,.&#;><"
#define CARACTERES_ALPHA "azertyuiopqsdfghjklmùwxcvbnAZERTYUIOPQSDFGHJKLMWXCVBN"


secDialog::secDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secDialog)
{
    ui->setupUi(this);
    ui->tabemploye->setModel(tmpemploye.afficher());
    ui->tabposte->setModel(tmpposte.afficher_poste());
    ui->comboBox_2->setModel(tmpemploye.afficher_nom());
 QPixmap bkgnd("C:/users/ASUS/desktop/Atelier_Connexion/q.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    correct->setMedia(QUrl("C:/users/ASUS/desktop/Atelier_Connexion/correct.mp3"));
    incorrect->setMedia(QUrl("C:/users/ASUS/desktop/Atelier_Connexion/incorrect.mp3"));
}

secDialog::~secDialog()
{
    delete ui;
}

void secDialog::on_pb_ajouter_clicked()
{

    int id = ui->lineEdit_id->text().toInt();
        QString nom= ui->lineEdit_nom->text();
        QString prenom= ui->lineEdit_prenom->text();
        int age= ui->lineEdit_date->text().toInt();
          QString email= ui->lineEdit_adresse->text();
          QDate datec= ui->dateEdit->date();
             QDate datee= ui->dateEdit_2->date();
            QString nom_poste= ui->comboBox_2->currentText();
            QString image =ui->chemin->text();

  {  Employe e(id,nom,prenom,age,email,datec,datee, nom_poste, image);

  bool test=e.ajouter();
  if(test)
{correct->play();
 ui->tabemploye->setModel(tmpemploye.afficher());//refresh

QMessageBox::information(this, QObject::tr("Ajouter un employer"),
                  QObject::tr("employer ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);



}
  else
   {  incorrect->play();
      QMessageBox::critical(this, QObject::tr("Ajouter un employer"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);}


  ui->lineEdit_id->clear();
  ui->lineEdit_nom->clear();
   ui->lineEdit_prenom->clear();
   ui->lineEdit_date->clear();
  ui->lineEdit_adresse->clear();
  ui->dateEdit->clear();
   ui->dateEdit_2->clear();
   ui->photo->clear();
}
 }




void secDialog::on_pb_supprimer_clicked()
{
     int id = ui->lineEdit_id_3->text().toInt();
     bool test=tmpemploye.supprimer(id);
  if(test)
  {correct->play();

        ui->tabemploye->setModel(tmpemploye.afficher());//refresh

     QMessageBox::information(this, QObject::tr("Supprimer un employer"),
                QObject::tr("employer supprimé.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);

   }
    else

  { incorrect->play();
      QMessageBox::critical(this, QObject::tr("Supprimer un publicite"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}
 ui->lineEdit_id_3->clear();

    }




void secDialog::on_pushButton_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    int age= ui->lineEdit_date->text().toInt();
     QString email= ui->lineEdit_adresse->text();
     QDate datec= ui->dateEdit->date();
        QDate datee= ui->dateEdit_2->date();
  QString nom_poste= ui->comboBox_2->currentText();
    QString image =ui->chemin->text();

        Employe e;

        {
      bool test=e.modifier(id,nom,prenom,age,email,datec,datee,nom_poste,image);
      if(test)
      {correct->play();
         ui->tabemploye->setModel(tmpemploye.afficher());//refresh
         QMessageBox::information(this, QObject::tr("Modifier un employer !"),
                           QObject::tr(" employer modifié ! \n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);


         ui->lineEdit_id->clear();
         ui->lineEdit_nom->clear();
          ui->lineEdit_prenom->clear();
          ui->lineEdit_date->clear();
         ui->lineEdit_adresse->clear();
         ui->dateEdit->clear();
          ui->dateEdit_2->clear();
           ui->photo->clear();
      }

      else

         { incorrect->play();
          QMessageBox::critical(this, QObject::tr("Modifier un employer"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);}
      }


    }


void secDialog::on_pb_recherche_clicked()
{
    QString prenom = ui->lineEdit_id_4->text();
    ui->tabemploye->setModel(tmpemploye.Rechercher(prenom));
}


void secDialog::on_trieremploye_clicked()
{

    bool test=true;
        if(test){

               { ui->tabemploye->setModel(tmpemploye.trier_id());
                QMessageBox::information(this, QObject::tr("trier employe"),
                            QObject::tr("employes trier.\n"
                                        "Voulez-vous enregistrer les modifications ?"),
                                   QMessageBox::Save
                                   | QMessageBox::Cancel,
                                  QMessageBox::Save);
}

            }
            else
                QMessageBox::critical(this, QObject::tr("trier employe"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

}



void secDialog::on_pb_ajouter_p_clicked()
{

    int id_poste = ui->lineEdit_id_p->text().toInt();
    QString nom_poste= ui->lineEdit_nom_p->text();
    int nbre_heures= ui->lineEdit_nb->text().toInt();
    int salaire= ui->lineEdit_salaire->text().toInt();
  Poste p (id_poste,nom_poste,nbre_heures, salaire);
  bool test=p.ajouter_poste();
  if(test)
{ correct->play();
      ui->comboBox_2->setModel(tmpemploye.afficher_nom());
      ui->tabposte->setModel(tmpposte.afficher_poste());//refresh
QMessageBox::information(this, QObject::tr("Ajouter poste"),
                  QObject::tr("poste ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
  {incorrect->play();
      QMessageBox::critical(this, QObject::tr("Ajouter poste"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);}


}

void secDialog::on_pb_modifier_p_clicked()
{
    int id_poste = ui->lineEdit_id_p->text().toInt();
    QString nom_poste= ui->lineEdit_nom_p->text();
    int nbre_heures= ui->lineEdit_nb->text().toInt();
    int salaire= ui->lineEdit_salaire->text().toInt();
    Poste p;
    bool test=p.modifier_poste(id_poste,nom_poste,nbre_heures,salaire);
 if(test)
   {correct->play();
      ui->comboBox_2->setModel(tmpemploye.afficher_nom());
      ui->tabposte->setModel(tmpposte.afficher_poste());//refresh
      QMessageBox::information(this, QObject::tr("Modifier poste !"),
                        QObject::tr(" poste modifié ! \n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
   }

   else {
       incorrect->play();
       QMessageBox::critical(this, QObject::tr("Modifier poste"),
                   QObject::tr("Erreur !.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
   }

}

void secDialog::on_pb_supprimer_p_clicked()
{
   int id_poste = ui->lineEdit_id_p_2->text().toInt();
    bool test=tmpposte.supprimer_poste(id_poste);
    if(test)
    {
        ui->comboBox_2->setModel(tmpemploye.afficher_nom());
        ui->tabposte->setModel(tmpposte.afficher_poste());//refresh
        QMessageBox::information(this, QObject::tr("Supprimer poste"),
                    QObject::tr("poste supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(this, QObject::tr("Supprimer poste"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}

void secDialog::on_pb_recherche_p_clicked()
{

    QString nom_poste = ui->lineEdit_nom_p_2->text();
   ui->tabposte->setModel(tmpposte.Rechercher_poste(nom_poste));
}

void secDialog::on_trie_poste_clicked()
{

    bool test=true;
        if(test){

               { ui->tabposte->setModel(tmpposte.trier_id_poste());
                QMessageBox::information(this, QObject::tr("trier poste"),
                            QObject::tr("poste trier.\n"
                                        "Voulez-vous enregistrer les modifications ?"),
                                   QMessageBox::Save
                                   | QMessageBox::Cancel,
                                  QMessageBox::Save);
}

            }
            else
                QMessageBox::critical(this, QObject::tr("trier poste"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

}





void secDialog::on_sendBtn_clicked()
{
        Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toUShort());
        connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


        smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
   QString status;
        if(status == "Message sent")
            QMessageBox::warning( this, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
   }



//++++++++++++++++controle de saisie+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


void secDialog::on_lineEdit_adresse_textChanged()
{

        QRegularExpression rx("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b",
                              QRegularExpression::CaseInsensitiveOption);
      ui->lineEdit_adresse ->setValidator(new QRegularExpressionValidator(rx, this));
      if(!ui->lineEdit_adresse->hasAcceptableInput())
         { ui->lineEdit_adresse->setStyleSheet("QLineEdit { color: red;}");
     ui->label_15->setText("exp@exp.com" );
     ui->label_15->setStyleSheet("QLabel { color:green;}");  }
      else
         { ui->lineEdit_adresse->setStyleSheet("QLineEdit { color: black;}");
      ui->label_15->setText("");}
}


void secDialog::on_lineEdit_date_textChanged(const QString &arg1)
{
   QString texte=arg1;
QString caracteresAlpha(CARACTERES_ALPHA);
for (int i=0; i<texte.size(); i++)
foreach (const QChar &y, caracteresAlpha)
    if(texte.at(i)==y)
   {
        texte[i]=' ';
        incorrect->play();
    }

 ui->lineEdit_date->setText(texte);

  }



void secDialog::on_lineEdit_id_textChanged(const QString &arg1)
{
    QString texte=arg1;
 QString caracteresAlpha(CARACTERES_ALPHA);
 for (int i=0; i<texte.size(); i++)
 foreach (const QChar &y, caracteresAlpha)
     if(texte.at(i)==y)
    {
         texte[i]=' ';
         incorrect->play();
     }

  ui->lineEdit_id->setText(texte);

}


void secDialog::on_lineEdit_id_p_textChanged(const QString &arg1)
{
    QString texte=arg1;
 QString caracteresAlpha(CARACTERES_ALPHA);
 for (int i=0; i<texte.size(); i++)
 foreach (const QChar &y, caracteresAlpha)
     if(texte.at(i)==y)
    {
         texte[i]=' ';
         incorrect->play();
     }

  ui->lineEdit_id_p->setText(texte);
}




void secDialog::on_lineEdit_nb_textChanged(const QString &arg1)
{
    QString texte=arg1;
 QString caracteresAlpha(CARACTERES_ALPHA);
 for (int i=0; i<texte.size(); i++)
 foreach (const QChar &y, caracteresAlpha)
     if(texte.at(i)==y)
    {
         texte[i]=' ';
         incorrect->play();
     }

  ui->lineEdit_nb->setText(texte);
}

void secDialog::on_lineEdit_salaire_textChanged(const QString &arg1)
{
    QString texte=arg1;
 QString caracteresAlpha(CARACTERES_ALPHA);
 for (int i=0; i<texte.size(); i++)
 foreach (const QChar &y, caracteresAlpha)
     if(texte.at(i)==y)
    {
         texte[i]=' ';
         incorrect->play();
     }

  ui->lineEdit_salaire->setText(texte);
}

void secDialog::on_lineEdit_nom_textEdited(const QString &arg1)
{
    QString texte=arg1;
QString caracteresEtrangers(CARACTERES_ETRANGERS);
for (int i=0; i<texte.size(); i++)
foreach (const QChar &y, caracteresEtrangers)
    if(texte.at(i)==y)
    {texte[i]=' ';
     incorrect->play();}

 ui->lineEdit_nom->setText(texte);

}


void secDialog::on_lineEdit_prenom_textEdited(const QString &arg1)
{
    QString texte=arg1;
QString caracteresEtrangers(CARACTERES_ETRANGERS);
for (int i=0; i<texte.size(); i++)
foreach (const QChar &y, caracteresEtrangers)
    if(texte.at(i)==y)
    {texte[i]=' ';
    incorrect->play();}

 ui->lineEdit_prenom->setText(texte);

}



void secDialog::on_lineEdit_nom_p_textChanged(const QString &arg1)
{

    QString texte=arg1;
QString caracteresEtrangers(CARACTERES_ETRANGERS);
for (int i=0; i<texte.size(); i++)
foreach (const QChar &y, caracteresEtrangers)
    if(texte.at(i)==y)
    {texte[i]=' ';
     incorrect->play();}

ui->lineEdit_nom_p->setText(texte);

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


void secDialog::on_imprimerRButton_clicked()
{

    QString strStream;
                QTextStream out(&strStream);

                const int rowCount = ui->tabemploye->model()->rowCount();
                const int columnCount = ui->tabemploye->model()->columnCount();
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
                    if (!ui->tabemploye->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tabemploye->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";

                // data table
                for (int row = 0; row < rowCount; row++) {
                    out << "<tr>";
                    for (int column = 0; column < columnCount; column++) {
                        if (!ui->tabemploye->isColumnHidden(column)) {
                            QString data =ui->tabemploye->model()->data(ui->tabemploye->model()->index(row, column)).toString().simplified();
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








void secDialog::on_pb_ajouter_image_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("choose"), "" , tr("image (*.png *.jpg *.jpeg *.bmp *.gif)"));
            if ( QString::compare(filename, QString()) != 0 )
            {
                QImage image;
                bool valid =image.load(filename);
                if (valid)
                {
                    ui->chemin->setText(filename);
                    image =image.scaledToWidth(ui->photo->width(),Qt::SmoothTransformation);
                    ui->photo->setPixmap(QPixmap::fromImage(image));
}
            }}

void secDialog::on_pb_ajouter_image_2_clicked()
{QString filename = QFileDialog::getOpenFileName(this,tr("choose"), "" , tr("image (*.png *.jpg *.jpeg *.bmp *.gif)"));
    if ( QString::compare(filename, QString()) != 0 )
    {
        QImage image;
        bool valid =image.load(filename);
        if (valid)
        {
            ui->chemin->setText(filename);
            image =image.scaledToWidth(ui->photo->width(),Qt::SmoothTransformation);
            ui->photo->setPixmap(QPixmap::fromImage(image));
}
    }}









void secDialog::on_tabemploye_activated(const QModelIndex &index)
{

   QString val=ui->tabemploye->model()->data(index).toString();
    QSqlQuery query;

    query.prepare("select * from Employe where NOM='"+val+"'");
    if(query.exec())
    {
        while (query.next())
        {

            ui->lineEdit_id->setText(query.value(0).toString());
            ui->lineEdit_nom->setText(query.value(1).toString());
            ui->lineEdit_prenom->setText(query.value(2).toString());
            ui->lineEdit_date->setText(query.value(3).toString());
            ui->lineEdit_adresse->setText(query.value(4).toString());
            ui->dateEdit->setDate(query.value(5).toDate());
            ui->dateEdit_2->setDate(query.value(6).toDate());
            ui->comboBox_2->setCurrentText(query.value(7).toString());
            ui->chemin->setText(query.value(8).toString()) ;
                    //AFFICHER LABEL IMAGE
                    QPixmap pix(ui->chemin->text());
                    int w =ui->photo->width();
                    int h =ui->photo->height();
                    ui->photo->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


       }
    }
}









void secDialog::on_tabemploye_clicked(const QModelIndex &index)
{
    QString val=ui->tabemploye->model()->data(index).toString();
     QSqlQuery query;

     query.prepare("select * from Employe where ID='"+val+"'");
     if(query.exec())
     {
         while (query.next())
         {

             ui->lineEdit_id_3->setText(query.value(0).toString());


}}
}


void secDialog::on_tabposte_activated(const QModelIndex &index)
{
QString val=ui->tabposte->model()->data(index).toString();
 QSqlQuery query;

 query.prepare("select * from Poste where nom_poste='"+val+"'");
 if(query.exec())
 {
     while (query.next())
     {

         ui->lineEdit_id_p->setText(query.value(0).toString());
         ui->lineEdit_nom_p->setText(query.value(1).toString());
         ui->lineEdit_nb->setText(query.value(2).toString());
         ui->lineEdit_salaire->setText(query.value(3).toString());

    }
 }
}




void secDialog::on_tabposte_clicked(const QModelIndex &index)
{
    QString val=ui->tabposte->model()->data(index).toString();
     QSqlQuery query;

     query.prepare("select * from Poste where  id_poste='"+val+"'");
     if(query.exec())
     {
         while (query.next())
         {

             ui->lineEdit_id_p_2->setText(query.value(0).toString());
}
     }
    }




void secDialog::on_retour_clicked()
{
    hide();
}

void secDialog::on_retour2_clicked()
{
    hide();
}

void secDialog::on_retour2_2_clicked()
{
    hide();
}





void secDialog::on_imprimerRButton_2_clicked()
{
    int id_poste = ui->lineEdit_id_p->text().toInt();
    QString nom_poste= ui->lineEdit_nom_p->text();
    int nbre_heures= ui->lineEdit_nb->text().toInt();
    int salaire= ui->lineEdit_salaire->text().toInt();



    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("C:/users/ASUS/desktop/Atelier_Connexion/"+nom_poste+".pdf");
    QPainter painter;
    if(! painter.begin(&printer))
    { qWarning("failed to open file");  }

QString id = QString::number(id_poste);
QString nbre = QString::number(nbre_heures);
QString s= QString::number(salaire);

           painter.setFont(QFont("Arial", 30));
            painter.setPen(Qt::black);
        painter.drawText(50,50,"BIENVENU ");
        painter.setPen(Qt::darkRed);
    painter.drawText(100,100,"SMART KINDERGARTEN ");
     painter.setPen(Qt::black);
    painter.drawText(50,200,"id_poste: "+id);
     painter.drawText(50,300,"nom_poste   : "+nom_poste);
     painter.drawText(50,400,"nbre_heures  : "+nbre);
     painter.drawText(50,500,"salaire   : "+s);

    painter.end();




}
