
#include "auditserveurmonowidget.h"
#include "ui_auditserveurmonowidget.h"

AuditServeurMonoWidget::AuditServeurMonoWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AuditServeurMonoWidget)
    , socketDialogueClient(nullptr)
    , process(nullptr)
{
    ui->setupUi(this);

    // Initialisation de l'attribut socketEcouteServeur

    connect(&socketEcouteServeur, SIGNAL(acceptError(QAbstractSocket::SocketError)),
            this, SLOT(onQTcpServer_acceptError(QAbstractSocket::SocketError)));
    connect(&socketEcouteServeur, SIGNAL(newConnection()),
            this, SLOT(onQTcpServer_newConnection()));

    // Initialisation de l'attribut process
    process = new QProcess(this);
    connect(process, SIGNAL(readyReadStandardOutput()),
            this, SLOT(onQProcess_readyReadStandardOutput()));

    ui->textEditLogs->append("Serveur initialisé.");
}

AuditServeurMonoWidget::~AuditServeurMonoWidget()
{
    delete ui;
    if (socketDialogueClient) {
        disconnect(socketDialogueClient, nullptr, this, nullptr);
        socketDialogueClient->deleteLater();
    }
    if (process) {
        process->deleteLater();
    }
}

void AuditServeurMonoWidget::on_pushButtonLancementServeur_clicked()
{
    if (!socketEcouteServeur.isListening()) {
        if (socketEcouteServeur.listen(QHostAddress::Any, 5555)) {
            ui->textEditLogs->append("Serveur démarré. En attente de connexion...");
        } else {
            ui->textEditLogs->append("Erreur lors du démarrage du serveur : " + socketEcouteServeur.errorString());
        }
    } else {
        ui->textEditLogs->append("Le serveur est déjà en écoute.");
    }
}

void AuditServeurMonoWidget::onQTcpServer_acceptError(QAbstractSocket::SocketError socketError)
{
    ui->textEditLogs->append("Erreur lors de l'acceptation de la connexion : " + socketEcouteServeur.errorString());
    // Ajoutez des messages d'erreur spécifiques ici
}

void AuditServeurMonoWidget::onQTcpServer_newConnection()
{
    ui->textEditLogs->append("Nouvelle connexion entrante.");


    socketDialogueClient = socketEcouteServeur.nextPendingConnection();
    ui->textEditLogs->append("Connexion établie avec succès.");

    socketDialogueClient = socketEcouteServeur.nextPendingConnection();
    connect(socketDialogueClient, SIGNAL(connected()),
            this, SLOT(onQTcpSocket_Connected()));
    connect(socketDialogueClient, SIGNAL(disconnected()),
            this, SLOT(onQTcpSocket_Disconnected()));
    connect(socketDialogueClient, SIGNAL(readyRead()),
            this, SLOT(onQTcpSocket_ReadyRead()));
    connect(socketDialogueClient, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(onQTcpSocket_ErrorOccurred(QAbstractSocket::SocketError)));
    connect(socketDialogueClient, SIGNAL(hostFound()),
            this, SLOT(onQTcpSocket_HostFound()));
    connect(socketDialogueClient, SIGNAL(stateChanged(QAbstractSocket::SocketError)),
            this, SLOT(onQTcpSocket_StateChanged(QAbstractSocket::SocketError)));
    connect(socketDialogueClient, SIGNAL(aboutToClose()),
            this, SLOT(onQTcpSocket_AboutToClose()));
    connect(socketDialogueClient, SIGNAL(bytesWritten(quint64)),
            this, SLOT(onQTcpSocket_BytesWritten(quint64)));


}
void AuditServeurMonoWidget::onQTcpSocket_Connected()
{
    ui->textEditLogs->append("Client connecté");
}

void AuditServeurMonoWidget::onQTcpSocket_Disconnected()
{
    disconnect(socketDialogueClient, nullptr, this, nullptr);
    socketDialogueClient->deleteLater();
    socketDialogueClient = nullptr;
    ui->textEditLogs->append("Client déconnecté");
}

void AuditServeurMonoWidget::onQTcpSocket_ReadyRead()
{
    QByteArray data = socketDialogueClient->readAll();
    // Traitez les données reçues

    // Exemple de traitement : affichez les données reçues dans le widget textEditLogs
    ui->textEditLogs->append("Données reçues du client : " + data);

    // Exemple de réponse
    QString reponse;

    // Utilisez une structure switch pour traiter différentes demandes
    switch (data.at(0)) {
    case 'u':
        reponse = "Nom d'utilisateur : " + QString(getenv("USER"));
        break;
    case 'c':
        reponse = "Nom de l'hôte : " + QHostInfo::localHostName();
        break;
    case 'o':
        // Utilisez QProcess pour récupérer l'architecture
        process->start("uname", QStringList("-p"));
        break;
    case 'a':
        // Utilisez QProcess pour récupérer l'OS
        process->start("uname");
        break;
    default:
        // Traitez d'autres cas si nécessaire
        reponse = "Commande non reconnue";
        break;
    }

    // Envoyez la réponse à la socket de dialogue avec le client
    if (!reponse.isEmpty()) {
        socketDialogueClient->write(reponse.toLatin1());
    }
}


void AuditServeurMonoWidget::onQTcpSocket_ErrorOccurred(QAbstractSocket::SocketError socketError)
{
    // Gérez l'erreur liée à la socket ici
    ui->textEditLogs->append("Erreur de la socket : " + socketDialogueClient->errorString());
}

void AuditServeurMonoWidget::onQTcpSocket_HostFound()
{
    // Gérez l'événement de recherche de l'hôte ici
    ui->textEditLogs->append("Recherche de l'hôte en cours...");
}

void AuditServeurMonoWidget::onQTcpSocket_StateChanged(QAbstractSocket::SocketError socketError)
{
    // Gérez le changement d'état de la socket ici
    if (socketDialogueClient->state() == QAbstractSocket::ConnectedState) {
        ui->textEditLogs->append("La socket est connectée.");
    } else if (socketDialogueClient->state() == QAbstractSocket::UnconnectedState) {
        ui->textEditLogs->append("La socket n'est pas connectée.");
    }
}

void AuditServeurMonoWidget::onQTcpSocket_AboutToClose()
{
    // Gérez l'événement juste avant la fermeture de la socket ici
    ui->textEditLogs->append("La socket est sur le point de se fermer.");
}

void AuditServeurMonoWidget::onQTcpSocket_BytesWritten(quint64 bytes)
{
    // Gérez l'événement d'écriture de données sur la socket ici
    ui->textEditLogs->append("Écriture de " + QString::number(bytes) + " octets sur la socket.");
}

void AuditServeurMonoWidget::onQProcess_readyReadStandardOutput()
{
    // Codez le slot de réception des données du processus ici
    QString reponse = process->readAllStandardOutput();
    if (!reponse.isEmpty())
        socketDialogueClient->write(reponse.toLatin1());
}
