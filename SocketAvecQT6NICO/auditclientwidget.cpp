#include "auditclientwidget.h"
#include "ui_auditclientwidget.h"

AuditClientWidget::AuditClientWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AuditClientWidget)
    ,socketDeDialogueAvecServeur(new QTcpSocket(this))
{
    ui->setupUi(this);
    connect(socketDeDialogueAvecServeur,&QTcpSocket::connected,this,&AuditClientWidget::onQTcpSocketConnected);
    connect(socketDeDialogueAvecServeur,&QTcpSocket::disconnected,this,&AuditClientWidget::onQTcpSocketDisconnected);
    connect(socketDeDialogueAvecServeur,&QTcpSocket::readyRead,this,&AuditClientWidget::onQTcpSocketReadyRead);
    connect(socketDeDialogueAvecServeur,&QTcpSocket::errorOccurred,this,&AuditClientWidget::onQTcpSocketErrorOccured);
    connect(socketDeDialogueAvecServeur,&QTcpSocket::hostFound,this,&AuditClientWidget::onQTcpSocketHostFound);
    connect(socketDeDialogueAvecServeur,&QTcpSocket::stateChanged,this,&AuditClientWidget::onQTcpSocketStateChanged);
    connect(socketDeDialogueAvecServeur,&QTcpSocket::aboutToClose,this,&AuditClientWidget::onQTcpSocketAboutToClose);
    connect(socketDeDialogueAvecServeur,&QTcpSocket::bytesWritten,this,&AuditClientWidget::onQTcpSocketBytesWritten);
    connect(socketDeDialogueAvecServeur,&QTcpSocket::channelBytesWritten,this,&AuditClientWidget::onQTcpSocketChannelBytesWritten);
    connect(socketDeDialogueAvecServeur,&QTcpSocket::channelReadyRead,this,&AuditClientWidget::onQTcpSocketChannelReadyRead);
    connect(socketDeDialogueAvecServeur,&QTcpSocket::destroyed,this,&AuditClientWidget::onQTcpSocketDestroyed);
    ui->lineEditAdresseIP->setText("127.0.0.1");
    ui->lineEditPort->setText("1025");
    ui->groupBoxInformationsClient->setEnabled(false);
}

AuditClientWidget::~AuditClientWidget()
{
    delete ui;
}


void AuditClientWidget::on_pushButtonConnexion_clicked()
{
    QString ip;
    QString port;

    ip = ui->lineEditAdresseIP->text();
    port = ui->lineEditPort->text();
    if(ui->pushButtonConnexion->text()=="Connexion"){
    socketDeDialogueAvecServeur->connectToHost(ip,port.toInt());
    ui->pushButtonConnexion->setText("Déconnexion");
    ui->groupBoxInformationsClient->setEnabled(true);
    }
    else{
    socketDeDialogueAvecServeur->disconnectFromHost();
    ui->pushButtonConnexion->setText("Connexion");
    ui->groupBoxInformationsClient->setEnabled(false);
    }
}

void AuditClientWidget::on_pushButtonOrdinateur_clicked()
{

}

void AuditClientWidget::on_pushButtonUtilisateur_clicked()
{

}

void AuditClientWidget::on_pushButtonArchitecture_clicked()
{

}

void AuditClientWidget::on_pushButtonOS_clicked()
{
    typeDeDemande="o";
    socketDeDialogueAvecServeur->write(typeDeDemande.toLatin1());
}

void AuditClientWidget::onQTcpSocketConnected()
{
    ui->textEditEtat->append("Socket Connected");
}

void AuditClientWidget::onQTcpSocketDisconnected()
{
    ui->textEditEtat->append("Socket Disconnected");
}

void AuditClientWidget::onQTcpSocketReadyRead()
{
    ui->textEditEtat->append("Socket Ready Read");
}

void AuditClientWidget::onQTcpSocketErrorOccured(QAbstractSocket::SocketError socketError)
{
    Q_UNUSED(socketError); // le paramètre n'est pas utilisé dans cette méthode
    ui->textEditEtat->append(socketDeDialogueAvecServeur->errorString());
}

void AuditClientWidget::onQTcpSocketHostFound()
{
    ui->textEditEtat->append("Socket Host Found");
}

void AuditClientWidget::onQTcpSocketStateChanged(QAbstractSocket::SocketState socketState)
{
    ui->textEditEtat->append("Socket State Changed");
}

void AuditClientWidget::onQTcpSocketAboutToClose()
{
    ui->textEditEtat->append("Socket About To Close");
}

void AuditClientWidget::onQTcpSocketBytesWritten(quint64 bytes)
{
    ui->textEditEtat->append("Socket Bytes Written");
}

void AuditClientWidget::onQTcpSocketChannelBytesWritten(int channel, quint64 bytes)
{
    ui->textEditEtat->append("Socket Channel Bytes Written");
}

void AuditClientWidget::onQTcpSocketChannelReadyRead(int channel)
{
    ui->textEditEtat->append("Socket Channel Ready Read");
}

void AuditClientWidget::onQTcpSocketReadChannelFinished()
{
    ui->textEditEtat->append("Socket Read Channel Finished");
}

void AuditClientWidget::onQTcpSocketDestroyed(QObject *obj)
{
    ui->textEditEtat->append("Socket Destroyed");
}

