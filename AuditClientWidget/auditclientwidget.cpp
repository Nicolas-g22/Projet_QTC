#include "auditclientwidget.h"
#include "ui_auditclientwidget.h"

AuditClientWidget::AuditClientWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AuditClientWidget)
    ,socketDeDialogueAvecServeur(nullptr)
{
    ui->setupUi(this);

    // creation de la socket de dialogue avec le serveur
    socketDeDialogueAvecServeur = new QTcpSocket ( this );

    // association des evenements liès à la socket avec les slots appelés
    connect(socketDeDialogueAvecServeur,&QTcpSocket::connected,this,&AuditClientWidget::onQTcpSocketConnected);
    connect(socketDeDialogueAvecServeur,&QTcpSocket::disconnected,this,&AuditClientWidget::onQTcpSocketDisconnected);
    connect(socketDeDialogueAvecServeur,&QTcpSocket::readyRead,this,&AuditClientWidget::onQTcpSocketReadyRead);
    connect(socketDeDialogueAvecServeur,&QTcpSocket::errorOccurred,this,&AuditClientWidget::onQTcpSocketErrorOccured);
    connect(socketDeDialogueAvecServeur,&QTcpSocket::hostFound,this,&AuditClientWidget::onQTcpSocketHostFound);
    connect(socketDeDialogueAvecServeur,&QTcpSocket::stateChanged,this,&AuditClientWidget::onQTcpSocketStateChanged);
    connect(socketDeDialogueAvecServeur,&QTcpSocket::aboutToClose,this,&AuditClientWidget::onQTcpSocketAboutToClose);
    //connect(socketDeDialogueAvecServeur,&QTcpSocket::bytesWritten,this,&AuditClientWidget::onQTcpSocketChannelBytesWritten);
    connect(socketDeDialogueAvecServeur,&QTcpSocket::channelBytesWritten,this,&AuditClientWidget::onQTcpSocketChannelBytesWritten);
    connect(socketDeDialogueAvecServeur,&QTcpSocket::channelReadyRead,this,&AuditClientWidget::onQTcpSocketChannelReadyRead);
    connect(socketDeDialogueAvecServeur,&QTcpSocket::readChannelFinished,this,&AuditClientWidget::onQTcpSocketReadChannelFinished);
    connect(socketDeDialogueAvecServeur,&QTcpSocket::destroyed,this,&AuditClientWidget::onQTcpSocketDestroyed);


}






void AuditClientWidget::on_pushButtonConnexion_clicked()
{
    if (ui->pushButtonConnexion->text()=="Connexion") {
        socketDeDialogueAvecServeur->connectToHost(ui->lineEditAdresseIP->text(), ui->lineEditPort->text().toInt());
    }
    else{
        socketDeDialogueAvecServeur->disconnectFromHost();
    }
}


void AuditClientWidget::on_pushButtonOrdinateur_clicked()
{
    typeDeDemande="c";
    socketDeDialogueAvecServeur->write(typeDeDemande.toLatin1());
}


void AuditClientWidget::on_pushButtonUtilisateur_clicked()
{
    typeDeDemande="u";
    socketDeDialogueAvecServeur->write(typeDeDemande.toLatin1());
}


void AuditClientWidget::on_pushButtonArchitecture_clicked()
{
    typeDeDemande="a";
    socketDeDialogueAvecServeur->write(typeDeDemande.toLatin1());
}


void AuditClientWidget::on_pushButtonOS_clicked()
{
    typeDeDemande="o";
    socketDeDialogueAvecServeur->write(typeDeDemande.toLatin1());
}

void AuditClientWidget::onQTcpSocketConnected()
{
    ui->textEditEtat->append("Connected");

    //Le bouton deviens "Déconnexion"
    ui->pushButtonConnexion->setText("Déconnexion");
    ui->lineEditAdresseIP->setEnabled(false);
    ui->lineEditPort->setEnabled(false);
    ui->groupBoxInformationsClient->setEnabled(true);
    ui->pushButtonOrdinateur->setEnabled(true);

    // Vider les linesEdit devant êtere remplis en cas de réponse du serveur
    ui->lineEditArchitecture->clear();
    ui->lineEditOrdinateur->clear();
    ui->lineEditOS->clear();
    ui->lineEditUtilisateur->clear();
}

void AuditClientWidget::onQTcpSocketDisconnected()
{

}

void AuditClientWidget::onQTcpSocketReadyRead()
{
    QByteArray buffer;
    if(socketDeDialogueAvecServeur->bytesAvailable() >0){
        // Lire l'ensemble des données disponibles et les mettre dans buffer
        buffer = socketDeDialogueAvecServeur->readAll();
    }

    if(typeDeDemande=="u"){
        // buffer.data() retourne le buffer sous forme de chaine
        ui->lineEditUtilisateur->setText(buffer.data());
    }

    if(typeDeDemande=="c"){
        ui->lineEditOrdinateur->setText(buffer.data());
    }

    if(typeDeDemande=="o"){
        ui->lineEditOS->setText(buffer.data());
    }

    if(typeDeDemande=="a"){
        ui->lineEditArchitecture->setText(buffer.data());
    }

}

void AuditClientWidget::onQTcpSocketErrorOccured(QAbstractSocket::SocketError socketError)
{
    Q_UNUSED(socketError); // Le paramètre n'est pas utilisé dans cette méthode
    ui->textEditEtat->append(socketDeDialogueAvecServeur->errorString());
}

void AuditClientWidget::onQTcpSocketHostFound()
{
    ui->textEditEtat->append("host found");
}

void AuditClientWidget::onQTcpSocketStateChanged(QAbstractSocket::SocketState socketState)
{
    switch (socketState){
    case QAbstractSocket::UnconnectedState : ui->textEditEtat->append("The socket is not connected.") ;break;
    case QAbstractSocket::HostLookupState :ui->textEditEtat->append("The socket is performing a host name lookup.") ;break;
    case QAbstractSocket::ConnectingState :ui->textEditEtat->append("The socket has started establishing a connection.");break;
    case QAbstractSocket::ConnectedState :ui->textEditEtat->append("A connection is established.");break;
    case QAbstractSocket::BoundState :ui->textEditEtat->append("The socket is bound to an address and port.");break;
    case QAbstractSocket::ClosingState :ui->textEditEtat->append("The socket is about to close (data may still be waiting to be written).");break;
    case QAbstractSocket::ListeningState :ui->textEditEtat->append("For internal use only.");break;
    }
}

void AuditClientWidget::onQTcpSocketAboutToClose()
{

}

void AuditClientWidget::onQTcpSocketChannelBytesWritten(int channel, quint64 bytes)
{

}

void AuditClientWidget::onQTcpSocketChannelReadyRead(int channel)
{

}

void AuditClientWidget::onQTcpSocketReadChannelFinished()
{

}

void AuditClientWidget::onQTcpSocketDestroyed(QObject *obj)
{

}


AuditClientWidget::~AuditClientWidget()
{
    delete ui;
}

