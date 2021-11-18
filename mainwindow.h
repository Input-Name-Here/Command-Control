#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionConfig_triggered();

    void on_actionMap_triggered();

    void on_VolumeSliderR_sliderMoved(int position);

    void on_VolumeSliderL_sliderMoved(int position);

private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
