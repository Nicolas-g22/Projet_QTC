#ifndef IHM_TP1_H
#define IHM_TP1_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class IHM_TP1; }
QT_END_NAMESPACE

class IHM_TP1 : public QWidget
{
    Q_OBJECT

public:
    IHM_TP1(QWidget *parent = nullptr);
    ~IHM_TP1();

private slots:
    void on_pushButtonSuite_clicked();

    void on_pushButtonDevine_clicked();

    void on_pushButtonLorentz_clicked();

    void on_pushButtonFonctionAge_clicked();

private:

    void afficherInfos();

    double poids;

    double taille;

    QString nom;

    QString prenom;

    int age;

    static const int NBIMC=6;

    static const int NBCORPULENCE=7;

    Ui::IHM_TP1 *ui;
};
#endif // IHM_TP1_H
