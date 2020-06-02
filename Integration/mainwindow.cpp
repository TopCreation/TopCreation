 #include "mainwindow.h"
#include "dialog.h"
#include "ui_mainwindow.h"
#include "connection.h"
#include<QMessageBox>
#include <QMediaPlaylist>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap bkgnd("C:/users/ASUS/desktop/Atelier_Connexion/ba.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    music->setMedia(QUrl("C:/users/ASUS/desktop/Atelier_Connexion/1.mp3"));
    correct->setMedia(QUrl("C:/users/ASUS/desktop/Atelier_Connexion/correct.mp3"));
    incorrect->setMedia(QUrl("C:/users/ASUS/desktop/Atelier_Connexion/incorrect.mp3"));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_login_clicked()
{


    if((ui->lineEdit_username->text()=="topcreation")&&(ui->lineEdit_mdp->text()=="esprit20"))
  {
correct->play();
        hide();
        Dialog *f = new  Dialog(this) ;
        f->show();

    }

    else {incorrect->play();
        QMessageBox::warning(this,"login","username and mdp is  not correct");
    }

 }



/*    void MainWindow::connexion(QString id, QString passe)
    {
        QMessageBox msg;
        QSqlDatabase bd = QSqlDatabase::addDatabase("QODBC");
        bd.setDatabaseName("Source_Projet2A");
        bd.setUserName(id);
        bd.setPassword(passe);

        if(!bd.open())
        {
            qDebug() <<"bug!!!";
            msg.setText("Erreur ID/Mot de passe !");
            msg.exec();
        }
        else
        {
            Dialog *f = new  Dialog(this) ;
            f->show();


            qDebug() <<"done!";
        }
    }

    void MainWindow::on_pushButton_login_clicked()
    {

       correct->play();
        connexion(ui->lineEdit_username->text(),ui->lineEdit_mdp->text());
    }
*/
