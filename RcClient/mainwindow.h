#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "serverchooserwidget.h"
#include "videoviewwidget.h"

#include <QMainWindow>
#include <QStackedLayout>
#include <QStatusBar>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QStackedLayout* stackedLayout;
    ServerChooserWidget* serverChooserWidget;
    VideoViewWidget* videoViewWidget;
};

#endif // MAINWINDOW_H
