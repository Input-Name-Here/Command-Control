#include "mainwindow.h"
#include "ui_mainwindow.h"


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
