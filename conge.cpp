#include "conge.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>

Conge::Conge()
{
  ref=0; duree_c=0;
  date_c=""; motif=""; etat_c="";
}

Conge::Conge(int ref,QString date_c,int duree_c,QString motif)
{
    this->ref=ref; this->duree_c=duree_c;
    this->date_c=date_c; this->motif=motif;
}
int Conge::getRef(){return ref;}
int Conge::getDuree_c(){return duree_c;}
QString Conge::getDate_c(){return date_c;}
QString Conge::getMotif(){return motif;}
QString Conge::getEtat_c(){return etat_c;}
void Conge::setRef(int ref){this->ref=ref;}
void Conge::setDuree_c(int duree_c){this->duree_c=duree_c;}
void Conge::setDate_c(QString date_c){this->date_c=date_c;}
void Conge::setMotif(QString motif){this->motif=motif;}
void Conge::setEtat_c(QString etat_c){this->etat_c=etat_c;}
bool Conge::ajouter()
{
    QSqlQuery query;

    QString ref_string=QString::number(ref);
    QString duree_c_string=QString::number(duree_c);


          query.prepare("INSERT INTO CONGE (REF, DATE_C, DUREE_C, MOTIF)"
                        "VALUES (:ref, :date_c, :duree_c, :motif)");
          query.bindValue(0, ref_string);
          query.bindValue(1, date_c);
          query.bindValue(2, duree_c_string);
          query.bindValue(3, motif);

          return query.exec();
}
QSqlQueryModel* Conge::afficher()
{
    QSqlQueryModel* model= new QSqlQueryModel();

          model->setQuery("SELECT * FROM CONGE");
          //model->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));
          //model->setHeaderData(1, Qt::Horizontal, QObject::tr("Salary"));
    return model;
}

