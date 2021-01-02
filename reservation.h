#ifndef RSERVATION_H
#define RSERVATION_H
#include<QString>
#include<QSqlQueryModel>
#include<QDate>
//tout
class reservation
{
public:
    reservation();
    reservation (int,int,QString,int,int);
    void setCIN(int);
    void setid(int);
    void setdatemariage(QString);
    void setacompteapayer(int);
    void setnumoffre(int);
    int  get_CIN();
    int get_id();
    QString get_datemariage();
    int get_acompteapayer();
    int get_numoffre();
    bool valider();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int,int,QString,int,int);
   QSqlQueryModel *tri();
   QSqlQueryModel *rechercher(QString);
   QSqlQueryModel *showidreservation() ;
private:
int CIN,id,acompteapayer,numoffre  ;
QString datemariage;

};


#endif // RSERVATION_H
