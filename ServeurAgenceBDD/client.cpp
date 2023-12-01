#include "client.h"

Client::Client(QObject *parent)    
{

}

int Client::getReferenceVol() const
{
    return referenceVol;
}

void Client::setReferenceVol(int newReferenceVol)
{
    referenceVol = newReferenceVol;
}

int Client::getNumeroPlace() const
{
    return numeroPlace;
}

void Client::setNumeroPlace(int newNumeroPlace)
{
    numeroPlace = newNumeroPlace;
}

QString Client::getNom() const
{
    return nom;
}

void Client::setNom(const QString &newNom)
{
    nom = newNom;
}

QString Client::getPrenom() const
{
    return prenom;
}

void Client::setPrenom(const QString &newPrenom)
{
    prenom = newPrenom;
}

QString Client::getEmail() const
{
    return email;
}

void Client::setEmail(const QString &newEmail)
{
    email = newEmail;
}

void Client::setSockClient( QTcpSocket *newClient)
{
    sockClient = newClient;
}

QTcpSocket *Client::getSockClient() const
{
    return sockClient;
}
