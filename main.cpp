#include "mainwindow.h"
#include "gestion_emp.h"
#include "gestion_cong.h"
#include "capteurtemp.h"
#include <QMessageBox>
<<<<<<< HEAD
#include <QDebug>
#include "connection.h"
#include <QApplication>
#include <QFile>

=======
#include "connexion.h"
#include"QtTextToSpeech/QTextToSpeech"
>>>>>>> 4f00f843afcdb778f75233acf25940670d89da8e
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    connection C;
    bool test= C.createConnection();
    MainWindow w;

<<<<<<< HEAD
    QFile styleSheetFile(":/styleSheet/Integrid.qss");
        styleSheetFile.open(QFile::ReadOnly);
        QString styleSheet = QLatin1String(styleSheetFile.readAll());
        a.setStyleSheet(styleSheet);
=======
    bool test=c.createconnect();
     MainWindow w;
    if(test)
    {w.show();
        QTextToSpeech * m_speech =new QTextToSpeech();
                            m_speech->say("La base des données est ouverte avec succès");
        QMessageBox::information(nullptr, QObject::tr("test is open"),
                    QObject::tr("connexion successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
>>>>>>> 4f00f843afcdb778f75233acf25940670d89da8e

    if (test)
        //qDebug() <<"Connexion reussite";
        QMessageBox::information(nullptr, QObject::tr("Database is open"), QObject::tr("Connection successful\nClick ok to exit"), QMessageBox::Ok);

    else
        //qDebug() <<"erreur de connexion";
        QMessageBox::critical(nullptr, QObject::tr("Database is not open"), QObject::tr("Connection failed\nClick cancel to exit"), QMessageBox::Cancel);

    w.show();

    return a.exec();
}
