#ifndef DIALOG3_H
#define DIALOG3_H

#include <QMediaPlayer>
#include <QDialog>
#include "fournisseurs.h"
#include "equipement.h"



namespace Ui {
class Dialog3;
}

class Dialog3 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog3(QWidget *parent = nullptr);
    QMediaPlayer *correct =new QMediaPlayer();
    QMediaPlayer *incorrect =new QMediaPlayer();
    ~Dialog3();

private slots:


 void on_fr_ajouter_clicked();

    void on_fr_modifier_clicked();

    void on_fr_supprimer_clicked();

    void on_fr_recherche_clicked();

    void on_trierfournisseurs_clicked();

    void on_pb_ajouter_p_clicked();

    void on_pb_modifier_p_clicked();

    void on_pb_supprimer_p_clicked();

    void on_pb_recherche_p_clicked();

    void on_trie_poste_clicked();

    //void on_pushButton_clicked();

    void on_sendBtn_2_clicked();

    void on_Imprimer_clicked();

    void on_tabfournisseurs_activated(const QModelIndex &index);

    void on_tabequipements_activated(const QModelIndex &index);


    void on_retour1_clicked();

    void on_retour1_2_clicked();

    void on_retour1_3_clicked();

private:
    Ui::Dialog3 *ui;
    fournisseurs tmpfournisseurs;
    equipements tmpequipements;
};




#endif // DIALOG3_H
