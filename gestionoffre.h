#ifndef GESTIONOFFRE_H
#define GESTIONOFFRE_H

#include <QDialog>
#include "offre.h"
#include "decorateur.h"
#include "gestion_salle.h"
#include <QPrinter>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QSqlError>
#include <QPrintDialog>
#include <QTextStream>
#include <QFileDialog>
#include <QFileInfo>
#include <QTextDocument>
#include <QSound>

namespace Ui {
class gestionoffre;
}

class gestionoffre : public QDialog
{
    Q_OBJECT

public:
    explicit gestionoffre(QWidget *parent = nullptr);
    ~gestionoffre();

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_17_clicked();

    void on_pushPDF_clicked();

    void on_lineEdit_3_textChanged(const QString &arg1);

    void on_taboffre_activated(const QModelIndex &index);

    void on_taboffre_clicked(const QModelIndex &index);

    void on_quitter_bt_clicked();


    void on_pushButton_clicked();

private:
    Ui::gestionoffre *ui;
    Offre O1;
    int offreSelect;
    Decorateur d;
    Gestion_salle s;
    QSound *son;
};

#endif // GESTIONOFFRE_H
