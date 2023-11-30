#ifndef IHM_SERVEUR_H
#define IHM_SERVEUR_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <avion.h>
#include <QDebug>
#include <QBuffer>
#include <QDataStream>

QT_BEGIN_NAMESPACE
namespace Ui { class IHM_Serveur; }
QT_END_NAMESPACE

class IHM_Serveur : public QWidget
{
    Q_OBJECT

public:
    IHM_Serveur(QWidget *parent = nullptr);
    ~IHM_Serveur();
    void envoyerVols();
    void envoyerPlaces(int ref);
    void ajouterReservationPlace(int ref, int place, QString nom, QString prenom, QString email);
    void genererListeVols();

public slots:

    void onQTcpSocket_connected();
    void onQTcpSocket_disconnected();
    void onQTcpSocket_readyRead();
    void onQTcpSocket_errorOccured(QAbstractSocket::SocketError socketError);
    void onQTcpServer_newConnexion();

private slots:
    void on_pushButtonLancer_clicked();

private:
    Ui::IHM_Serveur *ui;
    QTcpSocket *client;
    QTcpServer *socketEcoute;
    QList<avion*> lesVols;
};
#endif // IHM_SERVEUR_H
