#ifndef SALLE_H
#define SALLE_H
#include <QDialog>
#include "gestion_salle.h"
#include "decorateur.h"
namespace Ui {
class Salle;
}

class Salle : public QDialog
{
    Q_OBJECT

public:
    explicit Salle(QWidget *parent = nullptr);
    ~Salle();

private slots:
    void on_Ok_Ajoutsalle_clicked();

    void on_pb_supprimer1_clicked();

    void on_Ok_Ajouttheme_clicked();

    void on_pb_supprimertheme_clicked();

    void on_tri_nom_clicked();

    void on_tri_id_clicked();

    void on_Annuler_Supprimersalle_clicked();

    void on_Quitter_Ajoutsalle_clicked();

    void on_tri_id_dec_clicked();

    void on_tri_nom_dec_clicked();

    void on_Modifier_Modifiersalle_clicked();

    void on_Modifier_Modifiertheme_clicked();

    void on_Quitter_Ajouttheme_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_Annuler_Modifiersalle_clicked();

    void on_Annuler_Modifiertheme_clicked();

    void on_Annuler_Supprimertheme_clicked();

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

private:
    Ui::Salle *ui;
    Gestion_salle S;
    Decorateur T;
};

#endif // SALLE_H
