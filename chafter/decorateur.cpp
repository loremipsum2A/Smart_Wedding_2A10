#include "decorateur.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QSqlQueryModel>
#include <QMessageBox>

Decorateur::Decorateur()
{
id_dec=0;
prix_theme=0;
nom_dec=" ";
nom_theme=" ";
adresse_dec=" ";
}

Decorateur::Decorateur(int id_dec,int prix_theme,QString nom_dec,QString nom_theme,QString adresse_dec)
{
    this->id_dec=id_dec;
    this->prix_theme=prix_theme;
    this->nom_dec=nom_dec;
    this->nom_theme=nom_theme;
    this->adresse_dec=adresse_dec;
}

bool Decorateur::ajoutert()
{
    QSqlQuery query;

     QString id_dec_string=QString::number(id_dec);
     QString prix_string=QString::number(prix_theme);

     query.prepare("INSERT INTO DECORATEUR(id_dec,nom_dec,nom_theme,adresse_dec,prix_theme)"
                   "VALUES(:id_dec,:nom_dec,:nom_theme,:adresse_dec,:prix_theme)");

     query.bindValue(":id_dec",id_dec_string);
     query.bindValue(":nom_dec",nom_dec);
     query.bindValue(":nom_theme",nom_theme);
     query.bindValue(":adresse_dec",adresse_dec);
     query.bindValue(":prix_theme",prix_theme);

    return query.exec();
}

bool Decorateur::supprimert(int id_dec)
{
   QSqlQuery query;
    query.prepare("Delete from decorateur where id_dec=:id_dec");

    query.bindValue(0,id_dec);

  return query.exec();

}


QSqlQueryModel*Decorateur::affichert()
{

   QSqlQueryModel* model=new QSqlQueryModel();
   model->setQuery("SELECT* FROM decorateur");
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_DEC"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_DEC"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("NOM_THEME"));
   model->setHeaderData(3,Qt::Horizontal,QObject::tr("ADRESSE_DEC"));
   model->setHeaderData(4,Qt::Horizontal,QObject::tr("PRIX_THEME"));


   return model;
}

bool Decorateur::modifier(int id_dec,int prix_theme,QString nom_dec,QString nom_theme,QString adresse_dec)
{
    QSqlQuery query;

    QString id_dec_string= QString::number(id_dec);

    query.prepare("UPDATE DECORATEUR SET  id_dec = :id_dec, nom_dec=:nom_dec,nom_theme=:nom_theme, adresse_dec=:adresse_dec,prix_theme=:prix_theme  WHERE id_dec = :id_dec ");
    query.bindValue(":id_dec", id_dec_string);
    query.bindValue(":nom_dec", nom_dec);
    query.bindValue(":nom_theme", nom_theme);
    query.bindValue(":adresse_dec", adresse_dec);
    query.bindValue(":prix_theme", prix_theme);

    return  query.exec();
}

bool Decorateur::recherche(int id_dec,QString nom_dec,QString nom_theme)
{
    QMessageBox msgBox;
    QMessageBox msgBox1;
    QSqlQuery query;
    bool retour=0;
    int count=0;
    query.prepare("SELECT * FROM decorateur WHERE  id_dec= ? or nom_dec= ? or nom_theme= ?");
    query.addBindValue(id_dec);
    query.addBindValue(nom_dec);
    query.addBindValue(nom_theme);
    if(query.exec() )
        {
while (query.next())
   {
   count ++;
    }
if(count==1)
   {
    msgBox.setText("decorateur existe");
    msgBox.exec();
    retour=1;
   }
else if (count<1)
{
    msgBox.setText("decorateur n'existe pas");
    msgBox.exec();
        retour=0;
}
        }
    return retour;

}

