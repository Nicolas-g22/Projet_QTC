#ifndef DAB_WINDOW_H
#define DAB_WINDOW_H

#include <QWidget>
#include <QTcpSocket>
#include <QRadioButton>
#include <vol.h>
#include <QList>
#include <QBuffer>

QT_BEGIN_NAMESPACE
namespace Ui { class DAB_Window; }
QT_END_NAMESPACE

class DAB_Window : public QWidget
{
    Q_OBJECT

public:
    DAB_Window(QWidget *parent = nullptr);
    ~DAB_Window();

    //Fonctions
    void mettreAJourVols(QList<vol> lesVols);
    void mettreAJourOccupation(QList<int> placesOccupees);
    void demanderPlacesDisponibles(int ref);
    void reserver(int ref, int place, QString nom, QString prenom, QString email);

private slots:
    //Slots connexion graphique
    void on_pushButtonValider_clicked();
    void on_pushButtonConnexion_clicked();

    //Slots connexion manuel
    void onQComboBox_currentIndexChanged(int index);
    void onQTcpSocket_connected();
    void onQTcpSocket_disconnected();
    void onQTcpSocket_readyRead();
    void onQTcpSocket_errorOccured(QAbstractSocket::SocketError socketError);


private:
    Ui::DAB_Window *ui;
    QRadioButton places[15]; //Tableau pour créer les radioButton
    QTcpSocket socketClientAgence;

};
#endif // DAB_WINDOW_H
