#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Enfant.h"
#include "parent.h"
#include <QMainWindow>

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


    void on_ajouter_enfant_clicked();

    void on_Modifier_Enfant_clicked();

    void on_Supprimer_Enfant_clicked();

    void on_Trier_Enfant_clicked();

    void on_Recherche_Enfant_clicked();


    void on_Ajouter_Parent_clicked();



    void on_Modif_p_clicked();

     void on_Sup_p_clicked();


    void on_OK_clicked();



    void on_Recherche_p_clicked();

    void on_tabParent_activated(const QModelIndex &index);

    void on_tabEnfant_activated(const QModelIndex &index);

    void on_le_pic_linkActivated(const QString &link);

    void on_Iprim_clicked();

    void on_ok_clicked();





private:
    Ui::MainWindow *ui;
    Enfant tmpEnfant;
    Parent tmpParent;
};
#endif // MAINWINDOW_H
