#include "ihm_serveur.h"
#include "ui_ihm_serveur.h"

IHM_Serveur::IHM_Serveur(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::IHM_Serveur)
{
    ui->setupUi(this);
    connect(&socketEcoute,&QTcpServer::newConnection,this,&IHM_Serveur::onQTcpServer_newConnection);

    genererListeVols();
}

IHM_Serveur::~IHM_Serveur()
{
    delete ui;
}


void IHM_Serveur::on_pushButtonLancer_clicked()
{
    socketEcoute.listen(QHostAddress::Any,ui->spinBoxPortEcoute->value());

}

void IHM_Serveur::onQTcpSocket_connected()
{
    QTcpSocket *client=qobject_cast<QTcpSocket *>(sender());
    ui->textEditMessages->append("connecté avec "+client->peerAddress().toString()+":"+QString::number(client->peerPort()));

}

void IHM_Serveur::onQTcpSocket_disconnected()
{
    // récupérer la socket du client se déconnectant
    QTcpSocket *client=qobject_cast<QTcpSocket *>(sender());
    // récupérer l'index de ce client dans la liste
    int index= getIndexClient(client);
    // supprimer le client de la liste
    if (index!=-1)
    {
        listeClients.removeAt(index);
    }
    // afficher un message avec l'ip et le port du client deconnecté
    ui->textEditMessages->append("deconnexion de "+client->peerAddress().toString()+":"+QString::number(client->peerPort()));
}

int IHM_Serveur::getIndexClient(QTcpSocket *client){
    int indexClient=-1;
    int i=0;
    // recherche de l'index du client dans la liste des clients
    foreach (Client *c, listeClients) {

        if (c->getSockClient()==client){
            indexClient=i;
        }
        i++;
    }
    return indexClient;
}
void IHM_Serveur::onQTcpSocket_readyRead()
{
    quint16 taille=0;
    QChar commande;
    int ref;
    int indexClient;
    QTcpSocket *client=qobject_cast<QTcpSocket *>(sender());
    ui->textEditMessages->append("reception de donnees : "+QString::number(client->bytesAvailable())+" octets");
    if (client->bytesAvailable() >= (qint64)sizeof(taille))
    {

        QDataStream in(client);
        in >> taille;
        ui->textEditMessages->append("taille de donnees : "+QString::number(taille)+" octets");
        if (client->bytesAvailable() >= (qint64)taille)
        {
            in>>commande;
            ui->textEditMessages->append("Commande : "+QString(commande));
            switch (commande.toLatin1()) {
            case 'P':
                in>>ref;
                ui->textEditMessages->append("ref recue : "+QString::number(ref));
                indexClient=getIndexClient(client);
                listeClients.at(indexClient)->setReferenceVol(ref);
                envoyerPlaces(client,ref);

                break;
            case 'R':
                int place;
                QString nom, prenom,  email;
                in>>ref>>place>>nom>>prenom>>email;
                ui->textEditMessages->append("ref recue : "+QString::number(ref));
                ui->textEditMessages->append("place : "+QString::number(place));
                // recherche et mise à jour des infos client
                indexClient=getIndexClient(client);

                listeClients.at(indexClient)->setNom(nom);
                listeClients.at(indexClient)->setPrenom(prenom);
                listeClients.at(indexClient)->setEmail(email);
                listeClients.at(indexClient)->setReferenceVol(ref);
                listeClients.at(indexClient)->setNumeroPlace(place);


                ajouterReservationPlace(ref,place,nom,prenom,email);
                break;

            }
        }
    }
}

void IHM_Serveur::onQTcpSocket_errorOccured(QAbstractSocket::SocketError socketError)
{
    QTcpSocket *client=qobject_cast<QTcpSocket *>(sender());
    ui->textEditMessages->append(client->peerAddress().toString()+" : "+client->errorString());
}

void IHM_Serveur::onQTcpServer_newConnection()
{
    // récupération de la socket de communication du client
    QTcpSocket *client=socketEcoute.nextPendingConnection();

    // connection signal/slot pour la socket
    connect(client,&QTcpSocket::connected,this,&IHM_Serveur::onQTcpSocket_connected);
    connect(client,&QTcpSocket::disconnected,this,&IHM_Serveur::onQTcpSocket_disconnected);
    connect(client,&QTcpSocket::readyRead,this,&IHM_Serveur::onQTcpSocket_readyRead);
    connect(client,&QTcpSocket::errorOccurred,this,&IHM_Serveur::onQTcpSocket_errorOccured);
    // création et ajout du client dans la liste des clients
    Client *nouveauClient=new Client();
    nouveauClient->setSockClient(client);
    nouveauClient->setReferenceVol(lesVols.at(0)->infosVol.reference);
    listeClients.append(nouveauClient);
    // envoyer la listes des vols au client entrant
    envoyerVols(client);
    ui->textEditMessages->append("nouvelle connexion");
}

void IHM_Serveur::envoyerVols(QTcpSocket *client)
{

    quint16 taille=0;
    QBuffer tampon;
    QChar commande('V');
    // generation de la liste des vols
    QList <vol> vols;
    foreach(avion *a, lesVols)
    {
        vols<<a->infosVol;
    }

    tampon.open(QIODevice::WriteOnly);
    // association du tampon au flux de sortie
    QDataStream out(&tampon);
    // construction de la trame
    out<<taille<<commande<<vols;
    // calcul de la taille de la trame
    taille=(static_cast<quint16>(tampon.size()))-sizeof(taille);
    // placement sur la premiere position du flux pour pouvoir modifier la taille
    tampon.seek(0);
    //modification de la trame avec la taille reel de la trame
    out<<taille;
    // envoi du QByteArray du tampon via la socket
    client->write(tampon.buffer());
}

void IHM_Serveur::envoyerPlaces(QTcpSocket *client, int ref)
{
    quint16 taille=0;
    QBuffer tampon;
    QChar commande('P');
    // generation de la liste des vols
    QList <int> places;
    foreach(avion *a, lesVols)
    {
        if (a->infosVol.reference==ref)
        {
            places=a->siegesOccupees;
        }
    }

    tampon.open(QIODevice::WriteOnly);
    // association du tampon au flux de sortie
    QDataStream out(&tampon);
    // construction de la trame
    out<<taille<<commande<<places;
    // calcul de la taille de la trame
    taille=(static_cast<quint16>(tampon.size()))-sizeof(taille);
    // placement sur la premiere position du flux pour pouvoir modifier la taille
    tampon.seek(0);
    //modification de la trame avec la taille reel de la trame
    out<<taille;
    // envoi du QByteArray du tampon via la socket
    client->write(tampon.buffer());
}

void IHM_Serveur::ajouterReservationPlace(int ref, int place, QString nom, QString prenom, QString email)
{
    // mise a jour des places occupees pour le vol ref
    foreach(avion *a, lesVols)
    {
        if (a->infosVol.reference==ref)
        {
            a->siegesOccupees.append(place);
        }
    }
    // envoyer les places occupees à tous les clients reservant pour le vol
    // ayant la réference "ref"
    foreach (Client *client, listeClients) {
        if (client->getReferenceVol()==ref)
        {
            envoyerPlaces(client->getSockClient(),ref);
        }
    }
}

void IHM_Serveur::genererListeVols()
{
    avion *v1=new avion;
    v1->infosVol.reference=1234;
    v1->infosVol.denomination="Paris - Londre";
    v1->siegesOccupees<<1<<2<<4<<5<<12;

    avion *v2=new avion;
    v2->infosVol.reference=2345;
    v2->infosVol.denomination="Paris - New York";
    v2->siegesOccupees<<10<<12<<14;

    avion *v3=new avion;
    v3->infosVol.reference=3456;
    v3->infosVol.denomination="Paris - Sydney";
    v3->siegesOccupees<<1<<3<<8<<13<<15;

    lesVols.append(v1);
    lesVols.append(v2);
    lesVols.append(v3);

}

