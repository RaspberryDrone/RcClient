#ifndef SERVERCHOOSERWIDGET_H
#define SERVERCHOOSERWIDGET_H

#include "tcpconnector.h"
#include "udpreciever.h"

#include <QWidget>
#include <QLineEdit>
#include <QString>
#include <QHostAddress>
#include <QVector>
#include <QRegExp>
#include <QComboBox>

namespace Ui {
class ServerChooserWidget;
}

class ServerChooserWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ServerChooserWidget(QWidget *parent = 0);
    ~ServerChooserWidget();

signals:
    void emitChangeStatusbarText(QString text, int timeout);
    void emitFlipStackedUI(int widgetIndex);

public slots:
    void tcpReadyToSend();

private slots:
    void on_pushButton_connect_clicked();
    void enableConnectButton();
    void on_pushButton_exit_clicked();

private:
    bool checkLineEditInputsNumerical();

    Ui::ServerChooserWidget *ui;

    TcpConnector* tcpConnector;
    UdpReciever* udpReceiver;

    bool initalTcp = false;

    QString serverIp;
    QString serverPort;
    QString udpPort;
    QString videoBitrate;
    QString videoResolutionFps;

    QVector<int> intsForServer;
};

#endif // SERVERCHOOSERWIDGET_H
