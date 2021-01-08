#include "menu.h"
#include "ui_menu.h"
#include "ui_gestion_emp.h"
#include "gestion_emp.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "uimayssa.h"
#include "ui_uimayssa.h"
#include "ui_gestionoffre.h"
#include "ui_gestionreclamation.h"
#include "gestionoffre.h"
#include "gestionreclamation.h"
#include "gestion_de_salle.h"
#include "ui_gestion_de_salle.h"
#include "gestion_cong.h"
#include "ui_gestion_cong.h"
#include "ui_historique_avis.h"
#include "historique_avis.h"

Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    son=new QSound(":/sons/click.wav");
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_ge_emp_clicked()
{
    son->play();
    gestion_emp *ge = new gestion_emp();
    ge->show();
    this->hide();
}

void Menu::on_decnx_bt_clicked()
{
    son->play();
    MainWindow *ma = new MainWindow();
    ma->show();
    this->hide();
}

void Menu::on_ge_client_clicked()
{
    son->play();
    uimayssa *mayssa = new uimayssa();
    mayssa->show();
    this->hide();
}

void Menu::on_ge_offres_clicked()
{
    son->play();
    gestionoffre *go = new gestionoffre();
    go->show();
    this->hide();

}

void Menu::on_ge_reclam_clicked()
{
    son->play();
    gestionreclamation *gr = new gestionreclamation();
    gr->show();
    this->hide();
}

void Menu::on_ge_salles_clicked()
{
    son->play();
    gestion_de_salle *gs = new gestion_de_salle();
    gs->show();
    this->hide();

}

void Menu::on_ge_cong_clicked()
{
    son->play();
    gestion_cong *gc = new gestion_cong();
    gc->show();
    this->hide();
}

void Menu::on_pushButton_clicked()
{
    son->play();
    historique_avis *av = new historique_avis();
    av->show();
    this->hide();
}
