#include "offre.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QComboBox>
Offre::Offre()
{
num_offre=0 ; periode="" ; type="";prix_offre=0;
}

Offre::Offre(int num_offre,QString periode,QString type,int prix_offre,int id_traiteur,int id_troupe,int id_dec,int id)
{this->num_offre=num_offre;this->periode=periode;this->type=type;this->prix_offre=prix_offre;this->id_traiteur=id_traiteur;this->id_troupe=id_troupe;this->id_dec=id_dec;this->id=id;}
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
  QString id_traiteur_string=QString::number(id_traiteur);
  QString id_troupe_string=QString::number(id_troupe);
  QString id_dec_string=QString::number(id_dec);
  QString id_string=QString::number(id);

  query.prepare("INSERT INTO OFFRE (num_offre,periode,type,prix_offre,id_traiteur,id_troupe,id_dec,id) "
                "VALUES (:num_offre,:periode,:type,:prix_offre,:id_traiteur,:id_troupe,:id_dec,:id)");
  query.bindValue(":num_offre", num_offre_string);
  query.bindValue(":periode", periode);
  query.bindValue(":type",type);
  query.bindValue(":prix_offre", prix_offre_string);
  query.bindValue(":id_traiteur", id_traiteur_string);
  query.bindValue(":id_troupe", id_troupe_string);
  query.bindValue(":id_dec", id_dec_string);
  query.bindValue(":id", id_string);



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


  return  model;
}


QSqlQueryModel* Offre::rechercher(QString row,QString txt)
{
     QSqlQueryModel* model=new QSqlQueryModel();

     model->setQuery("SELECT * FROM OFFRE WHERE UPPER("+row+") LIKE UPPER('"+txt+"%')");

     return model;
}

//remplir id traiteur
void Offre::remplir1(QComboBox* c)
{
    QSqlQuery *query=new QSqlQuery();
    QSqlQueryModel* model=new QSqlQueryModel();
    query->prepare("SELECT ID_TRAITEUR FROM BUFFET ");
    query->exec();
    model->setQuery(*query);
    c->setModel(model);

}

//remplir id troupe
void Offre::remplir2(QComboBox* c)
{
    QSqlQuery *query=new QSqlQuery();
    QSqlQueryModel* model=new QSqlQueryModel();
    query->prepare("SELECT ID_TROUPE FROM TROUPE ");
    query->exec();
    model->setQuery(*query);
    c->setModel(model);

}
//remplir id dec
void Offre::remplir3(QComboBox* c)
{
    QSqlQuery *query=new QSqlQuery();
    QSqlQueryModel* model=new QSqlQueryModel();
    query->prepare("SELECT ID_DEC FROM DECORATEUR ");
    query->exec();
    model->setQuery(*query);
    c->setModel(model);

}
//remplir id salle
void Offre::remplir4(QComboBox* c)
{
    QSqlQuery *query=new QSqlQuery();
    QSqlQueryModel* model=new QSqlQueryModel();
    query->prepare("SELECT ID FROM SALLE ");
    query->exec();
    model->setQuery(*query);
    c->setModel(model);

}
