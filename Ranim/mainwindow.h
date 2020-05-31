#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "fournisseurs.h"
#include "equipements.h"
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

private:
    Ui::MainWindow *ui;
    fournisseurs tmpfournisseurs;
    equipements tmpequipements;
};
#endif // MAINWINDOW_H
