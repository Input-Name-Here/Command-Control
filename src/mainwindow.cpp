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
    //ui->tabWidget->setTabsClosable(true);

    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(on_sentMessage()));
    connect(ui->menuTabs, SIGNAL(aboutToShow()), this, SLOT(on_menuTabs_triggered()));



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

// on_action..._triggered():
//  These functions activate when menu elements are triggered
//  They will hide or show tabs on trigger.

void MainWindow::on_actionConfig_triggered()
{
    if(ui->actionConfig->isChecked())// If button is checked
    {
        int index = ui->tabWidget->indexOf(ui->tab_config);
        ui->tabWidget->removeTab(index);
    }
    else // If button is unchecked
    {
        ui->tabWidget->addTab(ui->tab_config, "Config");
    }
}

void MainWindow::on_actionMap_triggered()
{
    if(ui->actionMap->isChecked())// If button is checked
    {
        int index = ui->tabWidget->indexOf(ui->tab_map);
        ui->tabWidget->removeTab(index);
    }
    else // If button is unchecked
    {
        ui->tabWidget->addTab(ui->tab_map, "Map");
    }
}

void MainWindow::on_actionNet_triggered()
{
    if(ui->actionNet->isChecked())// If button is checked
    {
        int index = ui->tabWidget->indexOf(ui->tab_net);
        ui->tabWidget->removeTab(index);
    }
    else // If button is unchecked
    {
        ui->tabWidget->addTab(ui->tab_net, "Network");
    }
}

void MainWindow::on_actionComms_triggered()
{
    if(ui->actionComms->isChecked())// If button is checked
    {
        int index = ui->tabWidget->indexOf(ui->tab_comms);
        ui->tabWidget->removeTab(index);
    }
    else // If button is unchecked
    {
        ui->tabWidget->addTab(ui->tab_comms, "Comms");
    }
}

void MainWindow::on_actionData_triggered()
{
    if(ui->actionData->isChecked())// If button is checked
    {
        int index = ui->tabWidget->indexOf(ui->tab_data);
        ui->tabWidget->removeTab(index);
    }
    else // If button is unchecked
    {
        ui->tabWidget->addTab(ui->tab_data, "Data");
    }
}

void MainWindow::on_actionDocuments_triggered()
{
    if(ui->actionDocuments->isChecked())// If button is checked
    {
        int index = ui->tabWidget->indexOf(ui->tab_docs);
        ui->tabWidget->removeTab(index);
    }
    else // If button is unchecked
    {
        ui->tabWidget->addTab(ui->tab_docs, "Documents");
    }
}

void MainWindow::on_actionFeed_triggered()
{
    if(ui->actionFeed->isChecked())// If button is checked
    {
        int index = ui->tabWidget->indexOf(ui->tab_feed);
        ui->tabWidget->removeTab(index);
    }
    else // If button is unchecked
    {
        ui->tabWidget->addTab(ui->tab_feed, "Feed");
    }
}

void MainWindow::on_actionUsers_triggered()
{
    if(ui->actionUsers->isChecked())// If button is checked
    {
        int index = ui->tabWidget->indexOf(ui->tab_users);
        ui->tabWidget->removeTab(index);
    }
    else // If button is unchecked
    {
        ui->tabWidget->addTab(ui->tab_users, "Users");
    }
}



// Updates check value of actions in tab menu
void MainWindow::on_menuTabs_triggered(){
    // If tab exists, check action box

    // Config
    if(ui->tabWidget->indexOf(ui->tab_config)!=-1){
        ui->actionConfig->setChecked(true);
    } else { ui->actionConfig->setChecked(false); }

    // Map
    if(ui->tabWidget->indexOf(ui->tab_map)!=-1){
        ui->actionMap->setChecked(true);
    } else { ui->actionMap->setChecked(false); }

    // Network
    if(ui->tabWidget->indexOf(ui->tab_net)!=-1){
        ui->actionNet->setChecked(true);
    } else { ui->actionNet->setChecked(false); }

    // Comms
    if(ui->tabWidget->indexOf(ui->tab_comms)!=-1){
        ui->actionComms->setChecked(true);
    } else { ui->actionComms->setChecked(false); }

    // Data
    if(ui->tabWidget->indexOf(ui->tab_data)!=-1){
        ui->actionData->setChecked(true);
    } else { ui->actionData->setChecked(false); }

    // Docs
    if(ui->tabWidget->indexOf(ui->tab_docs)!=-1){
        ui->actionDocuments->setChecked(true);
    } else { ui->actionDocuments->setChecked(false); }

    // Feed
    if(ui->tabWidget->indexOf(ui->tab_feed)!=-1){
        ui->actionFeed->setChecked(true);
    } else { ui->actionFeed->setChecked(false); }

    // Feed
    if(ui->tabWidget->indexOf(ui->tab_users)!=-1){
        ui->actionUsers->setChecked(true);
    } else { ui->actionUsers->setChecked(false); }


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




