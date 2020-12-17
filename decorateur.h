#ifndef DECORATEUR_H
#define DECORATEUR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Decorateur
{
public:
    Decorateur();
    Decorateur(int,int,QString,QString,QString);

    int getiddec(){return id_dec;}
    int getprixtheme(){return prix_theme;}
    QString getnomdec(){return nom_dec;}
    QString getadressedec(){return adresse_dec;}
    QString getnomtheme(){return nom_theme;}

    void setiddec(int id_dec){this->id_dec=id_dec;}
    void setprixtheme(int prix_theme){this->prix_theme=prix_theme;}
    void setnomdec(QString nom_dec){this->nom_dec=nom_dec;}
    void setadressedec(QString adresse_dec){this->adresse_dec=adresse_dec;}
    void setnomtheme(QString nom_theme){this->nom_theme=nom_theme;}
    QSqlQueryModel* affichert();
    bool ajoutert();
    bool modifier(int);
    bool supprimert(int);
    bool rechercheiddec(int);
    bool recherchenomdec(QString);
    bool recherchenomtheme(QString);
    QSqlQueryModel* afficheriddec(int);
    QSqlQueryModel* affichernomdec(QString);
    QSqlQueryModel* affichernomtheme(QString);

private:
 int id_dec,prix_theme;
 QString adresse_dec,nom_dec,nom_theme;
};

#endif // DECORATEUR_H
