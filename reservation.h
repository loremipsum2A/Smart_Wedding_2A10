#ifndef RSERVATION_H
#define RSERVATION_H
#include<QString>
#include<QSqlQueryModel>


class reservation
{
public:
    reservation();
    reservation (int,int,int,int,int);
    void setCIN(int);
    void setid(int);
    void setdatemariage(int);
    void setacompteapayer(int);
    void setnumoffre(int);
    int  get_CIN();
    int get_id();
    int get_datemariage();
    int get_acompteapayer();
    int get_numoffre();
    bool valider();
    QSqlQueryModel* afficher();
    bool supprimer(int);

private:
int CIN,id,acompteapayer,numoffre ,datemariage ;


};


#endif // RSERVATION_H
