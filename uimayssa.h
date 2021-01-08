#ifndef UIMAYSSA_H
#define UIMAYSSA_H
#include "arduino.h"
#include <QDialog>
#include "client.h"
#include "reservation.h"
#include <QRegularExpression>
#include <QMainWindow>
#include "QPainter"
#include "QPdfWriter"
#include "QDesktopServices"
#include "QtPrintSupport/QPrinter"
#include <QPropertyAnimation>
#include <QSound>

namespace Ui {
class uimayssa;
}

class uimayssa : public QDialog
{
    Q_OBJECT

public:
    explicit uimayssa(QWidget *parent = nullptr);
    ~uimayssa();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_ajouter_clicked();
    void on_supprimer_clicked();
    void on_valider_reservation_clicked();
    void on_pushButton_3_clicked();
    void on_supprimer_reservation_clicked();
    void on_modifier_clicked();
    void on_tri_clicked();
    void on_comboBox_2_currentIndexChanged(const QString &arg1);
    void on_comboBox_4_currentIndexChanged(const QString &arg1);
    void on_resmodif_clicked();
    void on_recherche_textChanged(const QString &arg1);
    void on_lineEdit_CIN_returnPressed();
    void on_rechercheres_textChanged(const QString &arg1);
    void remplir_cb_clientcin();
    void on_pushButton_10_clicked();
    void on_pushButton_4_clicked();
    void update_label();
    void on_pushButton_5_clicked();

    void on_chat1_clicked();

private:
    Ui::uimayssa *ui;
    Client c;
        reservation R;
         QRegExp MRE ;
         int nbclient;
         QSound *son;
         Arduino A;
         QByteArray data;
};

#endif // UIMAYSSA_H
