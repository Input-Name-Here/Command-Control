#include <iostream>
#include <QScrollBar>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "socket/socket.h"
#include <string>


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
    Socket s = Socket(5000,"127.0.0.1"); //2885681153 loopback address
    s.Connect();

    /*puts(s.Recv().c_str());
    puts("New receive");
    puts(s.Recv().c_str());
    puts("New receive");
    puts(s.Recv().c_str());
    puts("New receive");
    puts(s.Recv().c_str());
    puts("New receive");*/
}

