#include <iostream>
#include <QScrollBar>
#include <string>

#include "networking/client.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace CommandControl::UI {

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setTabsClosable(true);

    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(on_sentMessage()));
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::new_msg(QString text)
{
    QScrollBar* bar = ui->textEdit->verticalScrollBar();
    ui->textEdit->append(text);
    bar->setValue(bar->maximum());
}

// SLOTS

void MainWindow::on_sentMessage()
{
    new_msg(ui->lineEdit_6->text());
    std::cout << ui->lineEdit_6->text().toStdString() << std::endl;
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

    //For comms shit, need to convert R and L values to Bal / Vol
}

void MainWindow::on_VolumeSliderL_sliderMoved(int position)
{

}

void MainWindow::on_NetConnectButton_clicked()
{
    printf("\nConnect\n");
    //Socket sock = Socket(5000,"127.0.0.1");
    //sock.Connect();
    CommandControl::Networking::Client s_client;
    s_client.Connect("www.google.com", 80);
}

}

