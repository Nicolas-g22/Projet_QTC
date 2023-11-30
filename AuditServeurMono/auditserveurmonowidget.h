// auditserveurmonowidget.h

#ifndef AUDITSERVEURMONOWIDGET_H
#define AUDITSERVEURMONOWIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QProcess>
#include <QTcpSocket>
#include <QHostInfo>
QT_BEGIN_NAMESPACE
namespace Ui { class AuditServeurMonoWidget; }
QT_END_NAMESPACE

class AuditServeurMonoWidget : public QWidget
{
    Q_OBJECT

public:
    AuditServeurMonoWidget(QWidget *parent = nullptr);
    ~AuditServeurMonoWidget();

private slots:
    void on_pushButtonLancementServeur_clicked();
    void onQTcpServer_acceptError(QAbstractSocket::SocketError socketError);
    void onQTcpServer_newConnection();
    void onQTcpSocket_Connected();
    void onQTcpSocket_Disconnected();
    void onQTcpSocket_ReadyRead();
    void onQTcpSocket_ErrorOccurred(QAbstractSocket::SocketError socketError);
    void onQTcpSocket_HostFound();
    void onQTcpSocket_StateChanged(QAbstractSocket::SocketError socketError);
    void onQTcpSocket_AboutToClose();
    void onQTcpSocket_BytesWritten(quint64 bytes);
    void onQProcess_readyReadStandardOutput();

private:
    Ui::AuditServeurMonoWidget *ui;
    QTcpServer socketEcouteServeur;
    QTcpSocket *socketDialogueClient; // Utilisation d'un pointeur
    QProcess *process; // Utilisation d'un pointeur
};

#endif // AUDITSERVEURMONOWIDGET_H
