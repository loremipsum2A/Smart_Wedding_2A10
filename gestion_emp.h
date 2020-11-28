#ifndef GESTION_EMP_H
#define GESTION_EMP_H

#include <QDialog>
#include "employe.h"

namespace Ui {
class gestion_emp;
}

class gestion_emp : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_emp(QWidget *parent = nullptr);
    ~gestion_emp();

private slots:
    void on_btajouter_emp_clicked();

    void on_btsupp_emp_clicked();

    void on_pushButton_3_clicked();

    void on_btmod_emp_clicked();

private:
    Ui::gestion_emp *ui;
    Employe E;
};

#endif // GESTION_EMP_H
