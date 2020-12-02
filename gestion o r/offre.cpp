#include "offre.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

Offre::Offre()
{
num_offre=0 ; periode="" ; type="";prix_offre=0;
}

Offre::Offre(int num_offre,QString periode,QString type,int prix_offre)
{this->num_offre=num_offre;this->periode=periode;this->type=type;this->prix_offre=prix_offre;}
int Offre:: getnum_offre(){return num_offre;}
QString Offre:: getperiode(){return periode;}
QString Offre:: gettype(){return type;}
int Offre:: getprix_offre(){return prix_offre;}
void Offre::setnum_offre(int num_offre) {this->num_offre=num_offre;}
void Offre::setperiode(QString periode) {this->periode=periode;}
void Offre::settype(QString type) {this->type=type;}
void Offre::setprix_offre(int prix_offre) {this->prix_offre=prix_offre;}

bool Offre::ajouter()
{

   QSqlQuery query;
  QString num_offre_string= QString::number(num_offre);
  QString prix_offre_string=QString::number(prix_offre);

  query.prepare("INSERT INTO OFFRE (num_offre,periode,type,prix_offre) "
                "VALUES (:num_offre,:periode,:type,:prix_offre)");
  query.bindValue(":num_offre", num_offre_string);
  query.bindValue(":periode", periode);
  query.bindValue(":type",type);
  query.bindValue(":prix_offre", prix_offre_string);
        return query.exec();

}
bool Offre::supprimer(int num_offre)
{
    QSqlQuery query;
            query.prepare("select * from OFFRE where num_offre=:num_offre");
            query.bindValue(0, num_offre);
            query.exec();
            if (query.next())
            {
             query.prepare(" Delete from OFFRE where num_offre=:num_offre");
             query.bindValue(0, num_offre);

                    query.exec();
                 return true;

            }

             return false;

}
QSqlQueryModel* Offre::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();


   model->setQuery("SELECT* FROM OFFRE");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("num_offre"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("periode"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix_offre"));

  return  model;
}


QSqlQueryModel* Offre::rechercher(QString row,QString txt)
{
     QSqlQueryModel* model=new QSqlQueryModel();

     model->setQuery("SELECT * FROM OFFRE WHERE UPPER("+row+") LIKE UPPER('"+txt+"%')");

     return model;
}
