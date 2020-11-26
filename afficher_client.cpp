#include "afficher_client.h"
#include "ui_afficher_client.h"

afficher_client::afficher_client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::afficher_client)
{
    ui->setupUi(this);
}

afficher_client::~afficher_client()
{
    delete ui;
}
void afficher_client::setclient(Client c )
{
}
