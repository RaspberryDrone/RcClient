#ifndef TCPCONNECTOR_H
#define TCPCONNECTOR_H

#include <QObject>
#include <QHostAddress>
#include <QString>
#include <QTcpSocket>
#include <QByteArray>

class TcpConnector : public QObject
{
    Q_OBJECT
public:
    explicit TcpConnector(QObject *parent = nullptr);
    void setupTcp(QHostAddress serverIp, QString port);
    void sendDataViaTcp(QByteArray bArray);

public slots:
    void useThisDataToSend(QByteArray bArray);

private slots:
    void readyToSend();

private:
    QTcpSocket *tcpSocket;

    bool socketReady = false;



};

#endif // TCPCONNECTOR_H
