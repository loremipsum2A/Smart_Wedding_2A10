#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include "menu.h"
#include "ui_menu.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    son=new QSound(":/sons/click.wav");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    son->play();
    Menu *m = new Menu();
    QString nom=ui->nom_le->text();
    QString prenom=ui->prenom_le->text();
    int CIN=ui->cin_le->text().toInt();

    if (E.login(nom,prenom,CIN))
    {
        m->show();
        this->hide();
    }

}
