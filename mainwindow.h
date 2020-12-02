#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"client.h"
#include"reservation.h"
#include <QRegularExpression>
#include <QMainWindow>



#include"QPainter"
#include"QPdfWriter"
#include"QDesktopServices"
#include"QtPrintSupport/QPrinter"
#include <QPropertyAnimation>

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

    void on_pushButton_2_clicked();

    void on_ajouter_clicked();

    void on_pushButton_6_clicked();


    void on_supprimer_clicked();

    void on_valider_reservation_clicked();

    void on_pushButton_3_clicked();

    void on_supprimer_reservation_clicked();

    void on_pushButton_5_clicked();

    void on_modifier_clicked();

    void on_tri_clicked();

    void on_comboBox_2_currentIndexChanged(const QString &arg1);

    void on_comboBox_4_currentIndexChanged(const QString &arg1);

    void on_pushButton_12_clicked();

    void on_resmodif_clicked();

    void on_lineEdit_adresse_email_cursorPositionChanged(int arg1, int arg2);

    void on_recherche_textChanged(const QString &arg1);

    void on_lineEdit_CIN_returnPressed();

    void on_pushButton_13_clicked();

    void on_pushButton_9_clicked();

    void on_rechercheres_textChanged(const QString &arg1);
    void remplir_cb_clientcin();

private:
    Ui::MainWindow *ui;
    Client c;
    reservation R;
 QRegExp MRE ;

};
#endif // MAINWINDOW_H
