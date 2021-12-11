#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class MainWindow;
}

namespace CommandControl::UI {

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void new_msg(QString text);


private slots:
    void on_actionConfig_triggered();
    void on_actionMap_triggered();
    void on_VolumeSliderR_sliderMoved(int position);
    void on_VolumeSliderL_sliderMoved(int position);
    void on_sentMessage();
    void on_menuTabs_triggered();


    void on_NetConnectButton_clicked();

    void on_actionComms_triggered();

    void on_actionNet_triggered();

    void on_actionData_triggered();

    void on_actionDocuments_triggered();

    void on_actionFeed_triggered();

    void on_actionUsers_triggered();

private:
    Ui::MainWindow *ui;

};

void hello();

}

#endif // MAINWINDOW_H
