#ifndef GESTION_AVIS_H
#define GESTION_AVIS_H

#include <QDialog>

namespace Ui {
class gestion_avis;
}

class gestion_avis : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_avis(QWidget *parent = nullptr);
    ~gestion_avis();

private:
    Ui::gestion_avis *ui;
};

#endif // GESTION_AVIS_H
