#include "ihm_serveur.h"
#include "ui_ihm_serveur.h"

IHM_Serveur::IHM_Serveur(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::IHM_Serveur)
{
    ui->setupUi(this);
    //Initialisation des variables necessaires
    client = new QTcpSocket(this);
    socketEcoute = new QTcpServer(this);

    //Création des connexion des slots
    connect(socketEcoute, &QTcpServer::newConnection, this, &IHM_Serveur::onQTcpServer_newConnexion);

    //Génération de la liste des vols
    genererListeVols();

}


//Liste des Fonctions/Slots
void IHM_Serveur::envoyerVols()
{
    quint16 taille=0;
    QBuffer tampon;
    QChar commande('V');
    // generation de la liste des vols
    QList <vol> vols;
    tampon.open(QIODevice::WriteOnly);
    foreach(avion *a, lesVols)
    {
        vols<<a->infosVol;
    }
    // construction de la trame à envoyer au client
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

void IHM_Serveur::envoyerPlaces(int ref)
{
    quint16 taille=0;
    QBuffer tampon;
    QChar commande('P');
    tampon.open(QIODevice::WriteOnly);
    // generation de la liste des vols

    QList <int> places;
    foreach(avion *a, lesVols)
    {
        if (a->infosVol.reference==ref)
        {
            places=a->siegesOccupees;
        }
    }
    // construction de la trame à envoyer au client
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
    // mise à jour des places réservées
    foreach(avion *a, lesVols)
    {
        if (a->infosVol.reference==ref)
        {
            a->siegesOccupees.append(place);
        }
    }
    // envoyer au client les places réservées pour le vol ayant la réf "ref"
    envoyerPlaces(ref);
}

void IHM_Serveur::genererListeVols()
{
    //Génération des 3 vols disponibles
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

void IHM_Serveur::onQTcpSocket_connected()
{
    //Message de connexion
    ui->textEditMessages->append("Connected.");
    qDebug() << "Connected";


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
        ui -> textEditMessages -> append();
}

void IHM_Serveur::onQTcpSocket_readyRead()
{
    //Message du "Ready Read"
    ui->textEditMessages->append("Socket ready to read.");
    qDebug() << "Socket ready to read.";

    quint16 taille=0;
    QChar commande;
    QList <vol> vols;
    QList <int> listePlaces;
    int ref;
    // Il y a au moins le champs taille d'arrive
    if (client->bytesAvailable() >= (qint64)sizeof(taille))
    {
        // Lecture de la taille de la trame
        QDataStream in(client);
        in >> taille;
        // Le reste de la trame est disponible
        if (client->bytesAvailable() >= (qint64)taille)
        {
            // Lecture de la commande
            in>>commande;
            switch (commande.toLatin1()) {

            case 'P':
                qDebug() << "P";
                in>>ref;
                envoyerPlaces(ref);
                break;

            case 'R':
                qDebug() << "R";
                int place;
                QString nom, prenom, mail;
                in >> ref >> place >> nom >> prenom >> mail;
                ajouterReservationPlace(ref, place, nom, prenom, mail);
                break;


            }
        }
    }


}

void IHM_Serveur::onQTcpSocket_errorOccured(QAbstractSocket::SocketError socketError)
{
    //Message d'erreur
    ui->textEditMessages->append("An error has occurred.");
    qDebug() << "An error has occurred.";



}

void IHM_Serveur::onQTcpServer_newConnexion()
{
    // récupération de la socket de communication du client
        QTcpSocket *client=socketEcoute->nextPendingConnection();

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
        ui->textEditMessages->append("nouvelle connexion"
                                     + nouveauClient->getSockClient()->peerAddress().toString()
                                     + nouveauClient->getSockClient()->peerPort());

}


void IHM_Serveur::on_pushButtonLancer_clicked()
{
    //Lancement du serveur

    if (!socketEcoute->isListening()) {
        if (socketEcoute->listen(QHostAddress::Any, ui->spinBoxEcoute->value())) {
            ui->textEditMessages->append("Serveur démarré.");
        } else {
            ui->textEditMessages->append("Erreur lors du démarrage du serveur : " + socketEcoute->errorString());
        }
    } else {
        ui->textEditMessages->append("Le serveur est déjà en écoute.");
    }
}

//Destructeur
IHM_Serveur::~IHM_Serveur()
{
    delete ui;
}


