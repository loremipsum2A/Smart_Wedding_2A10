#include "conge.h"
#include "employe.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QMessageBox>
#include <QDate>

Conge::Conge()
{
  ref=0; CIN=0;
  date_deb=""; date_fin=""; motif=""; etat_c="en cours";
}

Conge::Conge(int ref,int CIN,QString date_deb,QString date_fin,QString motif)
{
    this->ref=ref; this->CIN=CIN; this->date_deb=date_deb;
    this->date_fin=date_fin; this->motif=motif; etat_c="en cours";
}
int Conge::getRef(){return ref;}
QString Conge::getDate_deb(){return date_deb;}
QString Conge::getDate_fin(){return date_fin;}
QString Conge::getMotif(){return motif;}
QString Conge::getEtat_c(){return etat_c;}
void Conge::setRef(int ref){this->ref=ref;}
void Conge::setDate_deb(QString date_deb){this->date_deb=date_deb;}
void Conge::setDate_fin(QString date_fin){this->date_fin=date_fin;}
void Conge::setMotif(QString motif){this->motif=motif;}
void Conge::setEtat_c(QString etat_c){this->etat_c=etat_c;}

bool Conge::ajouter()
{
    QSqlQuery query;
    QMessageBox msgBox;
    QString ref_string=QString::number(ref);
    QString CIN_string=QString::number(CIN);


          query.prepare("INSERT INTO CONGE (REF, DATE_DEBUT, MOTIF,ETAT, CIN, DATE_FIN)"
                        "VALUES (:ref, :date_debut, :motif,:etat, :cin, :date_fin)");
          query.bindValue(":ref", ref_string);
          query.bindValue(":date_debut", date_deb);
          query.bindValue(":motif", motif);
          query.bindValue(":etat", etat_c);
          query.bindValue(":cin", CIN_string);
          query.bindValue(":date_fin", date_fin);
          QDate date1Compare = QDate::fromString(date_deb,"dd/MM/yyyy");
          QDate date2Compare = QDate::fromString(date_fin,"dd/MM/yyyy");
          qint64 days = date2Compare.daysTo(date1Compare);
          qDebug() << days;
          if(days>=0)
          {
              msgBox.setText("Verifier la date");
              msgBox.exec();
              return false;
          }
          return query.exec();
}

bool Conge::rechercher(int cin)
{
    QMessageBox msgBox;
    QSqlQuery query;
     QString CIN_string=QString::number(cin);
    query.prepare("SELECT * FROM CONGE WHERE CIN= :cin");
    query.bindValue(":cin", CIN_string);
    if (query.exec() && query.next())
    {
            return true;

    }
    else
    {

        msgBox.setText("non existant");
        msgBox.exec();
        return false;
    }
}

QSqlQueryModel* Conge::afficher_mesconges(int cin)
{
    QSqlQueryModel* model= new QSqlQueryModel();
    QString CIN_string=QString::number(cin);

          model->setQuery("SELECT * FROM CONGE WHERE CIN='"+CIN_string+"'");

    return model;
}

QSqlQueryModel* Conge::afficher_admin(QString etat)
{
    QSqlQueryModel* model= new QSqlQueryModel();

          model->setQuery("SELECT * FROM CONGE WHERE ETAT='"+etat+"'");

    return model;
}

bool Conge::rechercher_ref(int ref,QString etat)
{
    QMessageBox msgBox;
    QSqlQuery query;
     QString ref_string=QString::number(ref);
    query.prepare("SELECT * FROM CONGE WHERE REF= :ref");
    query.bindValue(":ref", ref_string);
    if (query.exec() && query.next())
    {
        query.prepare("UPDATE CONGE SET ETAT=:etat WHERE REF=:ref");
        query.bindValue(":etat",etat);
        query.bindValue(":ref",ref_string);
        query.exec();
        return true;

    }
    else
    {

        msgBox.setText("non existant");
        msgBox.exec();
        return false;
    }
}
