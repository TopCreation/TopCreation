#ifndef MAIL_H
#define MAIL_H

#include <QDialog>
#include "smtp.h"
#include <QtWidgets/QMessageBox>
#include <QFileDialog>

namespace Ui {
class mail;
}

class mail : public QDialog
{
    Q_OBJECT

public:
    explicit mail(QWidget *parent = nullptr);
    ~mail();

private slots:
    void sendMail();
    void mailSent(QString);
    void browse();

    void on_browseBtn_clicked();

private:
    Ui::mail *ui;
    QStringList files;

};

#endif // MAIL_H
