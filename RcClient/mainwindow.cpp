#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    stackedLayout = new QStackedLayout(this);
    serverChooserWidget = new ServerChooserWidget(this);
    videoViewWidget = new VideoViewWidget(this);

    stackedLayout->addWidget(serverChooserWidget);
    stackedLayout->addWidget(videoViewWidget);


    setCentralWidget(stackedLayout);

    //change statusbar text
    connect(serverChooserWidget, &ServerChooserWidget::emitChangeStatusbarText, ui->statusBar, &QStatusBar::showMessage);
    //flip stacked ui
    connect(serverChooserWidget, &ServerChooserWidget::emitFlipStackedUI, stackedLayout, &QStackedLayout::setCurrentIndex);
}

MainWindow::~MainWindow()
{
    delete ui;
}


