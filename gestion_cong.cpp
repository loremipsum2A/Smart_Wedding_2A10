#include "gestion_cong.h"
#include "ui_gestion_cong.h"
#include "conge.h"
#include <QMessageBox>

gestion_cong::gestion_cong(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_cong)
{
    ui->setupUi(this);
    ui->tab_cong->setModel(C.afficher());
}

gestion_cong::~gestion_cong()
{
    delete ui;
}

void gestion_cong::on_pushButton_clicked()
{

    int ref=ui->ref_ajouter->text().toInt();
    int duree_c=ui->duree_ajouter->text().toInt();
    QString date_c=ui->datecong_ajouter->text();
    QString motif=ui->motif_ajouter->text();


    Conge Cg(ref,date_c,duree_c,motif);
    bool test=Cg.ajouter();
     QMessageBox msgBox;

     if(test)

     {
         msgBox.setText("Ajout avec succes");
         ui->tab_cong->setModel(C.afficher());

     }
     else
         msgBox.setText("Echec d'ajout");

     msgBox.exec();
}

void gestion_cong::on_pushButton_4_clicked()
{
    int reference=ui->ref_consulter->text().toInt();
    if (C.getRef()==reference)
    C.setEtat_c("accepté");
}
