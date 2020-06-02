#ifndef DIALOG5_H
#define DIALOG5_H
#include "evenement.h"
#include "activity.h"
#include <QDialog>

namespace Ui {
class Dialog5;
}

class Dialog5 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog5(QWidget *parent = nullptr);
    ~Dialog5();

private slots:

   void on_fr_supprimer_ac_clicked();
   void  on_fr_recherche_ac_clicked();
   void on_trier_ac_clicked();
   void on_pb_ajouter_ev_clicked();
   void on_pb_modifier_ev_clicked();
   void on_pb_supprimer_ev_clicked();
    void  on_pb_recherche_ev_clicked();
    void on_trier_ev_clicked();


    void on_ajouter_ac_clicked();

    void on_modifier_ac_clicked();

    void on_retour_clicked();

    void on_retour_2_clicked();

    void on_retour2_2_clicked();

    void on_Imprimer_ac_clicked();

private:
    Ui::Dialog5 *ui;
    Activity tmpac;
    Event tmpev;
};

#endif // DIALOG5_H
