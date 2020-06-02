#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaPlaylist>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
     void connexion(QString,QString);
    QMediaPlayer *music =new QMediaPlayer();
    QMediaPlayer *correct =new QMediaPlayer();
    QMediaPlayer *incorrect =new QMediaPlayer();

private slots:
    void on_pushButton_login_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
