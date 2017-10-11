#include "videoviewwidget.h"
#include "ui_videoviewwidget.h"

VideoViewWidget::VideoViewWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoViewWidget)
{
    ui->setupUi(this);
}

VideoViewWidget::~VideoViewWidget()
{
    delete ui;
}
