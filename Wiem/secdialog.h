#ifndef SECDIALOG_H
#define SECDIALOG_H
#include "employe.h"
#include "poste.h"
#include "smtp.h"
//#include "capture.h"
#include <QMainWindow>
#include <QDialog>
#include <QMediaPlayer>

class QSqlTableModel;
class QPrinter;
namespace Ui {
class secDialog;
}

class secDialog : public QDialog
{
    Q_OBJECT

public:
    explicit secDialog(QWidget *parent = nullptr);
    ~secDialog();
    QMediaPlayer *correct =new QMediaPlayer();
    QMediaPlayer *incorrect =new QMediaPlayer();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pushButton_clicked();

    void on_pb_recherche_clicked();

    void on_trieremploye_clicked();

    void on_pb_ajouter_p_clicked();

    void on_pb_modifier_p_clicked();

    void on_pb_supprimer_p_clicked();

    void on_pb_recherche_p_clicked();

    void on_trie_poste_clicked();



    void on_sendBtn_clicked();



    void on_lineEdit_nom_textEdited(const QString &arg1);

    void on_imprimerRButton_clicked();

    void on_tabemploye_activated(const QModelIndex &index);

    void on_pb_ajouter_image_clicked();

    void on_pb_ajouter_image_2_clicked();


    void on_lineEdit_nom_p_textChanged(const QString &arg1);

    void on_tabemploye_clicked(const QModelIndex &index);

    void on_lineEdit_adresse_textChanged();


    void on_lineEdit_date_textChanged(const QString &arg1);

    void on_lineEdit_prenom_textEdited(const QString &arg1);

    void on_retour_clicked();

    void on_retour2_clicked();

    void on_lineEdit_nb_textChanged(const QString &arg1);

    void on_lineEdit_salaire_textChanged(const QString &arg1);

    void on_lineEdit_id_p_textChanged(const QString &arg1);

    void on_lineEdit_id_textChanged(const QString &arg1);

    void on_retour2_2_clicked();

    void on_tabposte_activated(const QModelIndex &index);

    void on_tabposte_clicked(const QModelIndex &index);

private:
    Ui::secDialog *ui;

    Employe tmpemploye;
    Poste tmpposte;

};

#endif // SECDIALOG_H



