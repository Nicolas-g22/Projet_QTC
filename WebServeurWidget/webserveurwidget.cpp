#include "webserveurwidget.h"
#include "ui_webserveurwidget.h"

WebServeurWidget::WebServeurWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WebServeurWidget)
{
    ui->setupUi(this);
    sock = new QWebSocketServer("cc", QWebSocketServer::NonSecureMode);
    majDate = new QTimer;
    connect(sock, &QWebSocketServer::newConnection, this, &WebServeurWidget::onQWebSocketServer_newConnection);
    connect(majDate, &QTimer::timeout, this, &WebServeurWidget::onQtimer_majDate);

}



void WebServeurWidget::onQWebSocketServer_newConnection()
{
    client = sock->nextPendingConnection();
    connect(client, &QWebSocket::textMessageReceived, this, &WebServeurWidget::onQWebSocket_textMessageReceived);
}

QString WebServeurWidget::onQWebSocket_textMessageReceived()
{

}

void WebServeurWidget::onQtimer_majDate()
{

}

WebServeurWidget::~WebServeurWidget()
{
    delete ui;
}
