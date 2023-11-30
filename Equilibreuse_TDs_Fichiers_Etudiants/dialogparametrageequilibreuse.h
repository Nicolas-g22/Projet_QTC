#ifndef DIALOGPARAMETRAGEEQUILIBREUSE_H
#define DIALOGPARAMETRAGEEQUILIBREUSE_H

#include <QDialog>
#include <QTimer>
#include <QTableWidgetItem>

#include "experience.h"


namespace Ui {
class DialogParametrageEquilibreuse;
}

class DialogParametrageEquilibreuse : public QDialog
{
    Q_OBJECT

public:
    explicit DialogParametrageEquilibreuse(Experience *_experience, QWidget *parent = nullptr);
    ~DialogParametrageEquilibreuse();
    void AfficherConfiguration();

private slots:
    void on_pushButtonEnregistrer_clicked();


private:
    Ui::DialogParametrageEquilibreuse *ui;
    Experience  *experience;
    typePalier  *paliers;

};

#endif // DIALOGPARAMETRAGEEQUILIBREUSE_H
