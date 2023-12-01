#ifndef IHM_SERVEUR_H
#define IHM_SERVEUR_H

#include <QWidget>
#include <QTcpSocket>
#include <QTcpServer>
#include <QDataStream>
#include <QBuffer>
#include "avion.h"
#include "client.h"
#include "interfaceaccessbddagence.h"

QT_BEGIN_NAMESPACE
namespace Ui { class IHM_Serveur; }
QT_END_NAMESPACE

class IHM_Serveur : public QWidget
{
    Q_OBJECT

public:
    IHM_Serveur(QWidget *parent = nullptr);
    ~IHM_Serveur();

private slots:
    void on_pushButtonLancer_clicked();

    void onQTcpSocket_connected();
    void onQTcpSocket_disconnected();
    void onQTcpSocket_readyRead();
    void onQTcpSocket_errorOccured(QAbstractSocket::SocketError socketError);

    void onQTcpServer_newConnection();
private:
    int getIndexClient(QTcpSocket *client);
    void envoyerVols(QTcpSocket *client);
    void envoyerPlaces(QTcpSocket *client,int ref);
    void ajouterReservationPlace(int ref,int place,QString nom, QString prenom, QString email);
    void genererListeVols();
    int diffuserPlaces(int ref);
    void afficherReservation();
    Ui::IHM_Serveur *ui;
    QTcpServer socketEcoute;
    QList <Client *>listeClients;
    QList <avion *> lesVols;
};
#endif // IHM_SERVEUR_H
