#include "connexion.h"

Connexion::Connexion()
{
}
bool Connexion::createconnect()
{
    bool test=false;

QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("club"); //kinder_association
db.setUserName("firas");//inserer nom de l'utilisateur
db.setPassword("esprit18");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;




    return  test;
}

void Connexion::closeconnect()
{ db.close() ;}
