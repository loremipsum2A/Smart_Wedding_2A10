#ifndef MAINWINDOW_H
#define MAINWINDOW_H
<<<<<<< HEAD
=======
#include"client.h"
#include"reservation.h"
#include"arduino.h"
#include <QRegularExpression>
#include <QMainWindow>

>>>>>>> 4f00f843afcdb778f75233acf25940670d89da8e

#include <QMainWindow>
#include "employe.h"
#include <QSound>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
<<<<<<< HEAD

private:
    Ui::MainWindow *ui;
    Employe E;
    QSound *son;
=======
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

private:
    Ui::MainWindow *ui;
    Client c;
    reservation R;
     QRegExp MRE ;
     arduino A;
     QByteArray data;
     int nbclient;

>>>>>>> 4f00f843afcdb778f75233acf25940670d89da8e
};
#endif // MAINWINDOW_H
