#ifndef VIDEOVIEWWIDGET_H
#define VIDEOVIEWWIDGET_H

#include <QWidget>

namespace Ui {
class VideoViewWidget;
}

class VideoViewWidget : public QWidget
{
    Q_OBJECT

public:
    explicit VideoViewWidget(QWidget *parent = 0);
    ~VideoViewWidget();

private:
    Ui::VideoViewWidget *ui;
};

#endif // VIDEOVIEWWIDGET_H
