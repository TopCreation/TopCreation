#include "dialog.h"
#include "ui_dialog.h"


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QPixmap bkgnd("C:/users/ASUS/desktop/Atelier_Connexion/q.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_emp_clicked()
{
    sec = new  secDialog(this);
    sec->show();
}

void Dialog::on_pushButton_emp_3_clicked()
{
    eq = new  Dialog3(this);
    eq->show();
}

void Dialog::on_pushButton_emp_2_clicked()
{
    enf = new  Dialog4(this);
    enf->show();
}

void Dialog::on_pushButton_emp_4_clicked()
{
    club = new  Dialog5(this);
    club->show();
}


void Dialog::on_pushButton_clicked()
{
    music->addMedia(QUrl("C:/users/ASUS/desktop/Atelier_Connexion/1.mp3"));
    music->addMedia(QUrl("C:/users/ASUS/desktop/Atelier_Connexion/2.mp3"));
    music->addMedia(QUrl("C:/users/ASUS/desktop/Atelier_Connexion/3.mp3"));

    music->setCurrentIndex(2);

    player->setPlaylist(music);
    player->play();
}

void Dialog::on_pushButton_2_clicked()
{
     player->pause();
}

void Dialog::on_pushButton_3_clicked()
{
     music->next();
}


void Dialog::on_horizontalSlider_sliderMoved(int position)
{
    volume=position;
  player->setVolume(volume);

}



