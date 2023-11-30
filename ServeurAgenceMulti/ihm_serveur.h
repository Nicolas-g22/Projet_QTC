#ifndef IHM_SERVEUR_H
#define IHM_SERVEUR_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <avion.h>
#include <QDebug>
#include <QBuffer>
#include <QDataStream>
#include "client.h"
QT_BEGIN_NAMESPACE
namespace Ui { class IHM_Serveur; }
QT_END_NAMESPACE

class IHM_Serveur : public QWidget
{
    Q_OBJECT

public:
    //Constructeur et destructeur
    IHM_Serveur(QWidget *parent = nullptr);
    ~IHM_Serveur();
    //Création des fonctions
    void envoyerVols(QTcpSocket* client);
    void envoyerPlaces(QTcpSocket* client, int ref);
    void ajouterReservationPlace(int ref, int place, QString nom, QString prenom, QString email);
    void genererListeVols();
    int getIndexClient(QTcpSocket* client);


private slots:
    //Création des slots
    void on_pushButtonLancer_clicked();
    void onQTcpSocket_connected();
    void onQTcpSocket_disconnected();
    void onQTcpSocket_readyRead();
    void onQTcpSocket_errorOccured(QAbstractSocket::SocketError socketError);
    void onQTcpServer_newConnexion();

private:
    //Déclaration des variables
    Ui::IHM_Serveur *ui;
    QTcpServer *socketEcoute;
    QList<avion*> lesVols;
    QList<Client*> listeClients;


};
#endif // IHM_SERVEUR_H
