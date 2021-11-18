#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_actionConfig_triggered()
{
    //if(!ui->actionConfig->isChecked()){
    //    ui->tabWidget->setTabVisable()
    //}
}

void MainWindow::on_actionMap_triggered()
{

}





void MainWindow::on_VolumeSliderR_sliderMoved(int position)
{
    int volR = ui->VolumeSliderR->value();
    int volL = ui->VolumeSliderR->value();
    ui->CommVolLabel->setText(QString::number(0));

    // For comms shit, need to convert R and L values to Bal / Vol
}

void MainWindow::on_VolumeSliderL_sliderMoved(int position)
{

}
