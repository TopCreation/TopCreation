 #include "mainwindow.h"
#include "dialog.h"
#include "ui_mainwindow.h"
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
    /*QString username = ui->lineEdit_username->text();
    QString mdp =ui->lineEdit_mdp->text();
     ui->lineEdit_mdp->setEchoMode(QLineEdit::NoEcho);
    mdp.setEchoMode(QLineEdit::Password);
    if(username == "wiwi" && mdp =="wiwi")
    {
        QMessageBox::information(this, "login","username and mdp is correct");
        hide();
        Dialog *f = new  Dialog(this) ;
        f->show();


    }
    else {
        QMessageBox::warning(this,"login","username and mdp is  not correct");
    }*/

    if((ui->lineEdit_username->text()=="wiem")&&(ui->lineEdit_mdp->text()=="esprit20"))
  {
correct->play();
        hide();
        Dialog *f = new  Dialog(this) ;
        f->show();

    }
    else if((ui->lineEdit_username->text()=="ranim")&&(ui->lineEdit_mdp->text()=="esprit20"))
    {
        hide();
        Dialog *f = new  Dialog(this) ;
        f->show();

    }
    else {incorrect->play();
        QMessageBox::warning(this,"login","username and mdp is  not correct");
    }

 }
