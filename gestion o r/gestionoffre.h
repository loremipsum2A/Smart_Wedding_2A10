#ifndef GESTIONOFFRE_H
#define GESTIONOFFRE_H

#include <QDialog>
#include "offre.h"
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

namespace Ui {
class GestionOffre;
}

class GestionOffre : public QDialog
{
    Q_OBJECT

public:
    explicit GestionOffre(QWidget *parent = nullptr);
    ~GestionOffre();

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_17_clicked();

    void on_pushPDF_clicked();

    void on_lineEdit_3_textChanged(const QString &arg1);

    void on_taboffre_activated(const QModelIndex &index);

    void on_taboffre_clicked(const QModelIndex &index);

private:
    Ui::GestionOffre *ui;
    Offre O1;
    int offreSelect;
};

#endif // GESTIONOFFRE_H
