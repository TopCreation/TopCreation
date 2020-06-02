#ifndef DIALOG4_H
#define DIALOG4_H
#include "enfant.h"
#include "parent.h"
#include <QDialog>

namespace Ui {
class Dialog4;
}

class Dialog4 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog4(QWidget *parent = nullptr);
    ~Dialog4();
private slots:


    void on_ajouter_enfant_clicked();

    void on_Modifier_Enfant_clicked();

    void on_Supprimer_Enfant_clicked();

    void on_Trier_Enfant_clicked();

    void on_Recherche_Enfant_clicked();



    void on_Ajouter_Parent_clicked();

    void on_Afficher_Parent_clicked();



    void on_Modifier_Parent_clicked();

    void on_Supprimer_Parent_clicked();


    void on_OK_clicked();

    void on_Recherche_p_clicked();

    void on_retour_clicked();

    void on_retour_2_clicked();

    void on_tabParent_activated(const QModelIndex &index);

    void on_tabEnfant_activated(const QModelIndex &index);


    void on_imprimerRButton_2_clicked();

private:
    Ui::Dialog4 *ui;
    Enfant tmpEnfant;
    Parent tmpParent;
};

#endif // DIALOG4_H






