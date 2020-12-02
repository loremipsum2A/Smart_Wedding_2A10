#include "gestion_salle.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QSqlQueryModel>
#include <QMessageBox>

Gestion_salle::Gestion_salle()
{
id=0;
nom=" ";
adresse=" ";
prix=0;
}
Gestion_salle::Gestion_salle(int id,QString nom,QString adresse,int prix)
{
 this->id=id;
 this->nom=nom;
 this->adresse=adresse;
 this->prix=prix;
}


bool Gestion_salle::ajouter()
{

QSqlQuery query;

 QString id_string=QString::number(id);
 QString prix_string=QString::number(prix);

 query.prepare("INSERT INTO SALLE(id,nom,adresse,prix)"
               "VALUES(:id,:nom,:adresse,:prix)");

 query.bindValue(":id",id_string);
 query.bindValue(":nom",nom);
 query.bindValue(":adresse",adresse);
 query.bindValue(":prix",prix);

return query.exec();
}
bool Gestion_salle::supprimer(int id)
{
   QSqlQuery query;
    query.prepare("Delete from salle where id=:id");

    query.bindValue(0,id);

    return query.exec();


}
QSqlQueryModel*Gestion_salle::afficher()
{

   QSqlQueryModel* model=new QSqlQueryModel();
   model->setQuery("SELECT* FROM salle");
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("ADRESSE"));
   model->setHeaderData(3,Qt::Horizontal,QObject::tr("PRIX"));


   return model;
}

bool Gestion_salle::modifier(int id,QString nom,QString adresse,int prix)
{
    QSqlQuery query;

    QString id_string= QString::number(id);

    query.prepare("UPDATE SALLE SET  id = :id, nom= :nom, adresse=:adresse,prix=:prix  WHERE id = :id ");
    query.bindValue(":id", id_string);
    query.bindValue(":nom", nom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":prix", prix);
    return  query.exec();
}

bool Gestion_salle::recherche(int id,QString nom,int prix)
{
    QMessageBox msgBox;
    QMessageBox msgBox1;
    QSqlQuery query;
    bool retour=0;
    int count=0;
    query.prepare("SELECT * FROM salle WHERE  id= ? or nom= ? or prix= ?");
    query.addBindValue(id);
    query.addBindValue(nom);
    query.addBindValue(prix);
    if(query.exec() )
        {
while (query.next())
   {
   count ++;
    }
if(count==1)
   {
    msgBox.setText("salle existe");
    msgBox.exec();
    retour=1;
   }
else if (count<1)
{
    msgBox.setText("salle n'existe pas");
        msgBox.exec();
        retour=0;
}
        }
    return retour;

}

