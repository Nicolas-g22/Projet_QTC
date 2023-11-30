#ifndef WEBSERVEURWIDGET_H
#define WEBSERVEURWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QWebSocket>
#include <QWebSocketServer>

QT_BEGIN_NAMESPACE
namespace Ui { class WebServeurWidget; }
QT_END_NAMESPACE

class WebServeurWidget : public QWidget
{
    Q_OBJECT

public:
    WebServeurWidget(QWidget *parent = nullptr);
    ~WebServeurWidget();

private:
    Ui::WebServeurWidget *ui;
    QWebSocketServer *sock;
    QWebSocket* client;
    QTimer* majDate;

public slots:
    void onQWebSocketServer_newConnection();
    QString onQWebSocket_textMessageReceived();
    void onQtimer_majDate();
};
#endif // WEBSERVEURWIDGET_H
