#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connexion.h"
#include"QtTextToSpeech/QTextToSpeech"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    connexion c;

    bool test=c.createconnect();
     MainWindow w;
    if(test)
    {w.show();
        QTextToSpeech * m_speech =new QTextToSpeech();
                            m_speech->say("La base des données est ouverte avec succès");
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
