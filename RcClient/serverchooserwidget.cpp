#include "serverchooserwidget.h"
#include "ui_serverchooserwidget.h"

ServerChooserWidget::ServerChooserWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ServerChooserWidget)
{
    ui->setupUi(this);
    ui->pushButton_connect->setEnabled(false);
    //Buttons are auto connected by name
    connect(ui->lineEdit_Serverip, QLineEdit::textEdited, this, ServerChooserWidget::enableConnectButton);
    connect(ui->lineEdit_Serverport, QLineEdit::textEdited, this, ServerChooserWidget::enableConnectButton);
    connect(ui->lineEdit_Udpport, QLineEdit::textEdited, this, ServerChooserWidget::enableConnectButton);

}

ServerChooserWidget::~ServerChooserWidget()
{
    delete ui;
}

/*
 *  Is triggered when the connect button is clicked
 */
void ServerChooserWidget::on_pushButton_connect_clicked()
{
    serverIpString = ui->lineEdit_Serverip->text();
    serverPortString = ui->lineEdit_Serverport->text();
    udpPortString = ui->lineEdit_Udpport->text();
    videoBitrateString = ui->lineEdit_Videobitrate->text();
    videoResolutionFpsString = ui->comboBox_resolutionfps->currentText();

    //check if lineedits are filled
    if(serverIpString.length() > 8
            && serverPortString.length() > 3 && serverPortString.length() < 6
            && udpPortString.length() > 3 && udpPortString.length() < 6
            && videoBitrateString.length() > 0)
    {
        //check if ip is valid
        QHostAddress serverIp;
        if(serverIp.setAddress(serverIpString))
        {
            //check if input is numerical
            if(checkLineEditInputsNumerical())
            {
                tcpConnector = new TcpConnector(this);


                udpReceiver = new UdpReciever(this);
                emit emitFlipStackedUI(1);
            }
            else
            {
                //signal to mainwindow void changeStatusbarText(QString text);
                emit emitChangeStatusbarText("Inputs need to be numerical" , 0);
                ui->pushButton_connect->setEnabled(false);
            }
        }
        else
        {
            //signal to mainwindow void changeStatusbarText(QString text);
            emit emitChangeStatusbarText("Ip Address not valid!", 0);
            ui->pushButton_connect->setEnabled(false);
        }

    }
}

/*
 *  Is triggered when input is made to the line edits
 */
void ServerChooserWidget::enableConnectButton()
{
    if(ui->lineEdit_Serverip->text().length() > 8
            && ui->lineEdit_Serverport->text().length() > 3 && ui->lineEdit_Serverport->text().length() < 6
            && ui->lineEdit_Udpport->text().length() > 3 && ui->lineEdit_Udpport->text().length() < 6
            && ui->lineEdit_Videobitrate->text().length() > 0)
    {
        ui->pushButton_connect->setEnabled(true);
    }
    else
        ui->pushButton_connect->setEnabled(false);

}

/*
 *  Is triggered when the Exit button is clicked
 */
void ServerChooserWidget::on_pushButton_exit_clicked()
{

}

/*
 *  Gets called when the tcpsocket in tcpconnector is emits ready signal
 */
void ServerChooserWidget::tcpReadyToSend()
{
    if(!initalTcp)
    {

    }
}

/*
 *  checks if input is numerical
 */
bool ServerChooserWidget::checkLineEditInputsNumerical()
{
    //check if ports are numerical inputs
    QRegExp re("\\d*");
    if(!re.exactMatch(serverPortString))
        return false;
    if(!re.exactMatch(udpPortString))
        return false;
    if(!re.exactMatch(videoBitrateString))
        return false;
    return true;
}


