#ifndef GESTIONRECLAMATION_H
#define GESTIONRECLAMATION_H

#include <QDialog>
#include "reclamation.h"
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
class gestionreclamation;
}

class gestionreclamation : public QDialog
{
    Q_OBJECT

public:
    explicit gestionreclamation(QWidget *parent = nullptr);
    ~gestionreclamation();


private slots:
    void on_pushButton_21_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_18_clicked();

    void on_pushPDF1_clicked();

    void on_lineEdit_7_textChanged(const QString &arg1);

    void on_tabrec_activated(const QModelIndex &index);

    void on_tabrec_clicked(const QModelIndex &index);



    void on_quitter_bt_clicked();

private:
    Ui::gestionreclamation *ui;
    reclamation R1;
    int recSelect;
    QSound *son;
};

#endif // GESTIONRECLAMATION_H
