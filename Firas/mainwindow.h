#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "evenement.h"
#include "activity.h"
#include <QMainWindow>
#include <QPieSeries>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajouter_ac_clicked();
    void on_modifier_ac_clicked();
   void on_supprimer_ac_clicked();
   void  on_recherche_ac_clicked();
   void on_trier_ac_clicked();
   void on_ajouter_ev_clicked();
   void on_modifier_ev_clicked();
   void on_supprimer_ev_clicked();
    void  on_recherche_ev_clicked();
    void on_trier_ev_clicked();
    void on_imprimer_ac_clicked();
    void on_tab_ac_activated(const QModelIndex &index);
    void on_tab_ev_activated(const QModelIndex &index);


private:
    Ui::MainWindow *ui;
   Activity tmpac;
   Event tmpev;
};
#endif // MAINWINDOW_H
