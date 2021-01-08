#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    GestionOffre GO;
    GO.setModal(true);
    GO.exec();

}

void MainWindow::on_pushButton_2_clicked()
{
    GestionReclamation GR;
    GR.setModal(true);
    GR.exec();
}
