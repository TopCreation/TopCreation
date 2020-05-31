#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "secdialog.h"
#include "dialog3.h"
#include "dialog4.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    QMediaPlaylist *music = new QMediaPlaylist;
    QMediaPlayer *player = new QMediaPlayer;

private slots:
  //  void on_pushButton_affich_clicked();


    void on_pushButton_emp_clicked();

    void on_pushButton_emp_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_horizontalSlider_sliderMoved(int position);

    void on_pushButton_emp_2_clicked();

private:
    Ui::Dialog *ui;
     secDialog *sec;
     Dialog3 *eq;
     Dialog4 *enf;
       int volume;
};


#endif // DIALOG_H
