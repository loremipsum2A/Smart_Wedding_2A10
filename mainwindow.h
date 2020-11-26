#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"client.h"

#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;
    Client c;
};
#endif // MAINWINDOW_H
