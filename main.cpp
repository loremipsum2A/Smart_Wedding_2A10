#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connexion.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    connexion c;
    bool test=c.createconnect();
    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("test is open"),
                    QObject::tr("connexion successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("test is not open"),
                    QObject::tr("connexion failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}
