#include "mainwindow.h"
#include "gestion_emp.h"
#include "gestion_cong.h"
#include "capteurtemp.h"
#include <QMessageBox>
#include <QDebug>
#include "connection.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    connection C;
    bool test= C.createConnection();
    MainWindow w;
    Capteurtemp cap;
    gestion_emp ge;
    gestion_cong gc;

    QFile styleSheetFile(":/styleSheet/Integrid.qss");
        styleSheetFile.open(QFile::ReadOnly);
        QString styleSheet = QLatin1String(styleSheetFile.readAll());
        a.setStyleSheet(styleSheet);

    if (test)
        //qDebug() <<"Connexion reussite";


        QMessageBox::information(nullptr, QObject::tr("Database is open"), QObject::tr("Connection successful\nClick ok to exit"), QMessageBox::Ok);

    else
        //qDebug() <<"erreur de connexion";
        QMessageBox::critical(nullptr, QObject::tr("Database is not open"), QObject::tr("Connection failed\nClick cancel to exit"), QMessageBox::Cancel);

    w.show();

    return a.exec();
}
