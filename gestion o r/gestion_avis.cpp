#include "gestion_avis.h"
#include "ui_gestion_avis.h"

gestion_avis::gestion_avis(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_avis)
{
    ui->setupUi(this);
}

gestion_avis::~gestion_avis()
{
    delete ui;
}
