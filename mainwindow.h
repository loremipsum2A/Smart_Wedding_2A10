#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include "troup.h"
#include "buffet.h"
//#include "arduino_v2.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_ajouterchef_clicked();

    void on_ajouterchef_clicked(bool checked);

    void on_ajoutertroup_clicked();

    void on_troup_sup_clicked();

    void on_chef_sup_clicked();

    void on_chef_sup_1_clicked();

    void on_music_tri_clicked();

    void on_gestion_music_tabBarClicked(int index);

    void on_gestion_buffet_tabBarClicked(int index);

    void on_chef_tri_clicked();

    void on_le_recherche_3_textChanged(const QString &arg1);

    void on_le_recherche_2_textChanged(const QString &arg1);

    void on_nonsatisfait_buffet_clicked();

    void on_nonsatisfait_buffet_2_clicked();

    void on_satisfait_music_clicked();

    void on_nonsatisfait_music_clicked();

private:
    Ui::MainWindow *ui;
    buffet b_tmp,b;
    troup t_tmp,t;

   // QByteArray data; // variable contenant les données reçues

   // arduino_v2 A; // objet temporaire
};

#endif // MAINWINDOW_H
