#ifndef GESTION_CONG_H
#define GESTION_CONG_H

#include <QDialog>
#include "conge.h"

namespace Ui {
class gestion_cong;
}

class gestion_cong : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_cong(QWidget *parent = nullptr);
    ~gestion_cong();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::gestion_cong *ui;
    Conge C;
};

#endif // GESTION_CONG_H
