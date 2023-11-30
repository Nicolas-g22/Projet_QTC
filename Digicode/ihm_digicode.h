#ifndef IHM_DIGICODE_H
#define IHM_DIGICODE_H

#include <QWidget>
#include <QJSEngine>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QTimer>
#include <string.h>
#define NBTOUCHES 12

QT_BEGIN_NAMESPACE
namespace Ui { class IHM_Digicode; }
QT_END_NAMESPACE

class IHM_Digicode : public QWidget
{
    Q_OBJECT

public:
    IHM_Digicode(QWidget *parent = nullptr);
    ~IHM_Digicode();


    QPushButton *touches[NBTOUCHES];
    QGridLayout *grille;
    QLineEdit *afficheur;
    void gestionModeNormal();
    void gestionModeAdmin();
    void onQPushButtonClicked();

private:
    Ui::IHM_Digicode *ui;
    QString codeOuverture = "1234";
    QString codeAdmin = "7777";
    bool modeAdmin;
};
#endif // IHM_DIGICODE_H
