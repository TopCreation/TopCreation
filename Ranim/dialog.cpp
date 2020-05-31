#include "dialog.h"
#include "ui_dialog.h"


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QPixmap bkgnd("C:/Users/Ranim Ben Aafia/Desktop/lina2.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

Dialog::~Dialog()
{
    delete ui;
}








void Dialog::on_pushButton_emp_5_clicked()
{
    mai = new  MainWindow(this);
    mai->show();
}
