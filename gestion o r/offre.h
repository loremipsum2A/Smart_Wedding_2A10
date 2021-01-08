#ifndef OFFRE_H
#define OFFRE_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QComboBox>

class Offre
{
public:
    Offre();
    Offre(int,QString,QString,int,int,int,int,int);
    int getnum_offre();
    QString getperiode();
    QString gettype();
    int getprix_offre();
    void setnum_offre(int);
    void setperiode(QString);
    void settype(QString);
    void setprix_offre(int);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    QSqlQueryModel* rechercher(QString,QString);
    void remplir1(QComboBox*);
    void remplir2(QComboBox*);
    void remplir3(QComboBox*);
    void remplir4(QComboBox*);

private:
int num_offre,prix_offre;
QString periode,type;
int id_traiteur,id,id_dec,id_troupe;
};

#endif // OFFRE_H
