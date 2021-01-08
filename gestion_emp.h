#ifndef GESTION_EMP_H
#define GESTION_EMP_H

#include <QDialog>
#include <QRegularExpression>
#include "employe.h"
#include "gestion_cong.h"

#include <QSound>

namespace Ui {
class gestion_emp;
}

class gestion_emp : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_emp(QWidget *parent = nullptr);
    ~gestion_emp();

    private:
       gestion_cong *g;

private slots:
    void on_btajouter_emp_clicked();

    void on_btsupp_emp_clicked();

    void on_pushButton_clicked();

    void on_btmod_emp_clicked();

    void on_recherche_multicritere_clicked();

    void on_tri_multicritere_clicked();

    void on_bt_imprimer_clicked();

    void on_bt_pdf_clicked();

    void on_quitter_bt_clicked();

    void on_excel_clicked();

private:
    Ui::gestion_emp *ui;
    Employe E;
    QSound *son;

};

#endif // GESTION_EMP_H
