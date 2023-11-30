#ifndef DIALOGCONFIGUREREXPERIENCE_H
#define DIALOGCONFIGUREREXPERIENCE_H

#include <QDialog>
#include "experience.h"

namespace Ui {
class DialogConfigurerExperience;
}

class DialogConfigurerExperience : public QDialog
{
    Q_OBJECT

public:
    explicit DialogConfigurerExperience(Experience *_experience, QWidget *parent = 0);
    ~DialogConfigurerExperience();

private slots:
    void on_pushButtonValider_clicked();

    void on_pushButtonAnnuler_clicked();

private:
    Ui::DialogConfigurerExperience *ui;
    Experience *experience;
};

#endif // DIALOGCONFIGUREREXPERIENCE_H
