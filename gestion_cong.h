#ifndef GESTION_CONG_H
#define GESTION_CONG_H

#include <QDialog>
#include "conge.h"

#include <QSound>

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

   // void on_pushButton_4_clicked();

      void on_consulter_mesconges_clicked();

      void on_bt_admin_clicked();

      void on_bt_accepter_clicked();

      void on_bt_refuser_clicked();

      void on_bt_imprimer_cg_clicked();

      void on_bt_pdf_cg_clicked();

private:
    Ui::gestion_cong *ui;
    Conge C;
    QSound *son;
};

#endif // GESTION_CONG_H
