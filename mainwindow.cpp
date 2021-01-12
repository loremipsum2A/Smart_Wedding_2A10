#include "mainwindow.h"
#include "ui_mainwindow.h"



#include <QComboBox>
#include <QCheckBox>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->chef_table->setModel(b.afficher());
    ui->tab_troup->setModel(t.afficher());
    ui->chef_table->setModel(b_tmp.afficher());
    ui->tab_troup->setModel(t_tmp.afficher());

   /* int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));*/
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_ajouterchef_clicked()
{
    QMessageBox msg;






    int id_traiteur=ui->id_b->text().toInt();
    QString nom_chef=ui->nom_b->text();
    int prix=ui->prix_b->text().toInt();
    QString type=ui->type_b->text();



 buffet b(id_traiteur,nom_chef,prix,type);

bool test=b.ajouter();
if(test){
    msg.setText("ajout succesful");
   ui->chef_table->setModel(b_tmp.afficher());

}
    else{msg.setText("echec ajout");}
msg.exec();
}

void MainWindow::on_ajoutertroup_clicked()
{
    QMessageBox msg;
    int id_troup=ui->id_t->text().toInt();
    QString nom_troop=ui->nom_t->text();
    int rating=ui->rat_t->text().toInt();
    QString genre=ui->ger_t->text();



     troup t(id_troup,nom_troop,rating,genre);

    bool test=t.ajouter();
    if(test){
        msg.setText("ajout succesful");
       ui->tab_troup->setModel(t_tmp.afficher());
      // ui->label_6->setText(QString::number(t.max()));


    }
        else{msg.setText("echec ajout");}
    msg.exec();
}

void MainWindow::on_troup_sup_clicked()
{
    QMessageBox msg;
    troup t;
    int id_troup=ui->sup_t->text().toInt();
    bool test=t.supprimer(id_troup);
    if(test){
        msg.setText("suppression succesful");
       ui->tab_troup->setModel(t_tmp.afficher());

    }
        else{msg.setText("echec suppression");}
    msg.exec();
}

void MainWindow::on_chef_sup_1_clicked()
{
    QMessageBox msg;
    msg.setText("echec suppression");
    buffet b;
     int id_traiteur=ui->sup_b->text().toInt();
    bool test=b.supprimer(id_traiteur);
    if(test){
        msg.setText("suppression succesful");
       ui->chef_table->setModel(b_tmp.afficher());

    }
        else{msg.setText("echec suppression");}
    msg.exec();
}

void MainWindow::on_music_tri_clicked()
{
    QString colone=ui->colone_tri1->currentText();
    QString ordre=ui->ordre_tri1->currentText();
    troup t;
    ui->tab_troup->setModel(t.tri1(colone,ordre));
}

void MainWindow::on_gestion_music_tabBarClicked(int index)
{
    ui->tab_troup->setModel(t.afficher());
}

void MainWindow::on_gestion_buffet_tabBarClicked(int index)
{
    ui->chef_table->setModel(b.afficher());
}

void MainWindow::on_chef_tri_clicked()
{
    QString colone=ui->colone_tri2->currentText();
    QString ordre=ui->ordre_tri2->currentText();
    buffet b;
    ui->chef_table->setModel(b.tri1(colone,ordre));
}

void MainWindow::on_le_recherche_3_textChanged(const QString &arg1)
{
    buffet b;
     ui->chef_table->setModel(b.rechercher(ui->colone_tri2_2->currentText(),arg1));
}

void MainWindow::on_le_recherche_2_textChanged(const QString &arg1)
{
    troup t;
     ui->tab_troup->setModel(t.rechercher(ui->colone_tri1_2->currentText(),arg1));
}

/*
void MainWindow::on_nonsatisfait_buffet_clicked()
{
    A.write_to_arduino("1");
}

void MainWindow::on_nonsatisfait_buffet_2_clicked()
{
    A.write_to_arduino("2");
}

void MainWindow::on_satisfait_music_clicked()
{
    A.write_to_arduino("1");
}

void MainWindow::on_nonsatisfait_music_clicked()
{
    A.write_to_arduino("2");
}
*/
