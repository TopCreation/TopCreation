#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
  //  void on_pushButton_affich_clicked();

  //normalment mch fama 3 lena?p nusnhbuton nn wahde khw lboxmassege fl mainwindow y5dm mregl am fl mainwindow nn tawa lizdnha sarelha l'ajout wala lé eyy mregl



    void on_pushButton_emp_5_clicked();

private:
    Ui::Dialog *ui;
      MainWindow *mai;
};


#endif // DIALOG_H
