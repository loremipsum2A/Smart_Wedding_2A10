#ifndef gestion_de_salle_H
#define gestion_de_salle_H
#include <QDialog>
#include "gestion_salle.h"
#include "decorateur.h"
#include <QPropertyAnimation>
#include"arduino.h"
#include <QSound>

QT_BEGIN_NAMESPACE
namespace Ui {
class gestion_de_salle;
}
QT_END_NAMESPACE

class gestion_de_salle : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_de_salle(QWidget *parent = nullptr);
    ~gestion_de_salle();

private slots:
    void on_Ok_Ajoutsalle_clicked();

    void on_pb_supprimer1_clicked();

    void on_Ok_Ajouttheme_clicked();

    void on_pb_supprimertheme_clicked();

    void on_tri_nom_clicked();

    void on_tri_id_clicked();

    void on_Quitter_Ajoutsalle_clicked();

    void on_tri_id_dec_clicked();

    void on_tri_nom_dec_clicked();

    void on_Modifier_Modifiersalle_clicked();

    void on_Modifier_Modifiertheme_clicked();

    void on_tri_nom_2_clicked();

    void on_tri_id_2_clicked();

    void on_tri_id_dec_2_clicked();

    void on_tri_nom_dec_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pdf_salle_clicked();

    void on_pdf_decorateur_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_imprimerdeco_clicked();

    void on_consulter_mod_salle_clicked();

    void on_Modifier_Modifiertheme_2_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_Quitter_Ajoutsalle_2_clicked();

    void on_captemp_clicked();

private:
    Ui::gestion_de_salle *ui;
    Gestion_salle S;
    Decorateur T;
    QPropertyAnimation *animation;
    Arduino A ;
    QSound *son;

};

#endif // SALLE_H
