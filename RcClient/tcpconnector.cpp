#include "tcpconnector.h"

TcpConnector::TcpConnector(QObject *parent) : QObject(parent)
{

}

void TcpConnector::setupTcp(QHostAddress serverIp, QString port)
{
    tcpSocket = new QTcpSocket(this);

    connect(tcpSocket, &QTcpSocket::connected, this, &TcpConnector::readyToSend);
}


