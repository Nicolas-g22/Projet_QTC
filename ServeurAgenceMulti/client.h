#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>

class Client : public QObject
{
    Q_OBJECT
public:
    //Constructeur
    explicit Client(QObject *parent = nullptr);
    //Fonctions
    int getReferenceVol();
    void setReferenceVol(int newReferenceVol);
    int getNumeroPlace();
    void setNumeroPlace(int newNumeroPlace);
    QString getNom();
    void setNom(const QString& newNom);
    QString getPrenom();
    void setPrenom(const QString& newPrenom);
    QString getMail();
    void setEmail(const QString& newEmail);
    QTcpSocket* getSockClient();
    void setSockClient(QTcpSocket* newClient);


private:
    //Initialisation des variables
    int referenceVol;
    int numeroPlace;
    QString nom;
    QString prenom;
    QString email;
    QTcpSocket* sockClient;


signals:

};

#endif // CLIENT_H
