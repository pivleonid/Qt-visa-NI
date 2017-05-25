#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <fstream>
#include <complex>
#include <vector>
#include "fftw3.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

        /// логика кнопок
        connect(ui->connectButton, SIGNAL(clicked(bool)), this, SLOT(connect_button()));
        connect(ui->DisconnectButton, SIGNAL(clicked(bool)),this, SLOT(discon_button()));
        connect(ui->ButtonBufferClear,SIGNAL(clicked(bool)),this, SLOT(clear_log()));
        ui->DisconnectButton->setEnabled(false);
        connect(ui->RST, SIGNAL(clicked(bool)),this,SLOT(ResetDevice()));
        connect(ui->buttonTrace, SIGNAL(clicked(bool)),this, SLOT(TraceButton()));
        ui->labelFSL->setStyleSheet("background:red;");
        ui->labelTDS->setStyleSheet("background:red;");
///
      vector<complex<double> > data(1000);
    //complex<double> data[1000];
    data[0] = { 1 , 0 };
    data[1] = { 1 , 0 };
    data[2] = { 1 , 0 };
    data[3] = { 1 , 0 };
    data[4] = { 1 , 0 };
    //
    data[100] = { 1 , 0 };
    data[101] = { 1 , 0 };
    data[102] = { 1 , 0 };
    data[103] = { 1 , 0 };
    data[104] = { 1 , 0 };
    ///
    ///
    data[200] = { 1 , 0 };
    data[201] = { 1 , 0 };
    data[202] = { 1 , 0 };
    data[203] = { 1 , 0 };
    data[204] = { 1 , 0 };
    ///
    ///
    data[300] = { 1 , 0 };
    data[301] = { 1 , 0 };
    data[302] = { 1 , 0 };
    data[303] = { 1 , 0 };
    data[304] = { 1 , 0 };
    ///
    data[400] = { 1 , 0 };
    data[401] = { 1 , 0 };
    data[402] = { 1 , 0 };
    data[403] = { 1 , 0 };
    data[404] = { 1 , 0 };
    ///
    complex<double>  data_out1[1000];
    // создаем план для библиотеки fftw
    //(FFTW_FORWARD - прямое, FFTW_BACKWARD - обратное)
   // fftw_plan plan = fftw_plan_dft_2d(10, 10, (fftw_complex*)&data[0], (fftw_complex*)&data_out1[0], FFTW_FORWARD, FFTW_ESTIMATE);
fftw_plan plan = fftw_plan_dft_1d(100, (fftw_complex*)&data[0], (fftw_complex*)&data_out1[0], FFTW_FORWARD, FFTW_ESTIMATE);
//    // преобразование Фурье
    fftw_execute(plan);
    fftw_destroy_plan(plan);

//    // выводим в файл результат преобразования Фурье (должна получиться Дельта-функция)
    ofstream out("spektr.txt");
       for(size_t i=0; i<1000; ++i)
       {
          out<<data_out1[i]<<endl;
       }
}
//=======================================================
MainWindow::~MainWindow()
{
   if(mainStateDevice == fsl)
       delete FSL_Device;
   if(mainStateDevice == tds)
       delete TDS_Device;
    delete ui;
}

//=======================================================
void MainWindow::connect_button(){
    InitializeDevice(ui->DeviceBox->currentText());
    if(connectCompliteButton){
    //сделать серыми кноку и комбобокс
    ui->connectButton->setEnabled(false);
    ui->DeviceBox->setEnabled(false);
    ui->DisconnectButton->setEnabled(true);
}
}
//=======================================================
void MainWindow::discon_button(){
    if( mainStateDevice == fsl){
        FSL_Device->DisconnectDevice();
        delete FSL_Device;
        mainStateDevice = off;
    }
    if(mainStateDevice == tds){
        TDS_Device->DisconnectDevice();
        delete TDS_Device;
        mainStateDevice = off;
    }
    connectCompliteButton = false;
    ui->labelFSL->setStyleSheet("background:red;");
    ui->labelTDS->setStyleSheet("background:red;");
    ui->connectButton->setEnabled(true);
    ui->DeviceBox->setEnabled(true);
    ui->DisconnectButton->setEnabled(false);

}
//=======================================================

void MainWindow::clear_log(){
ui->LogList->clear();
}
//=======================================================

void MainWindow::InitializeDevice(QString Divice){
 if("FSL" == Divice){
    FSL_Device = new FSL;
    mainStateDevice = fsl;
    ui->labelFSL->setStyleSheet("background:green;");
 }
 if("TDS2024C" == Divice){
     TDS_Device = new TDS2024C;
     mainStateDevice = tds;
     QString Message = TDS_Device->ConnectDevice(ui->DeviceBox_2->currentText(),ui->adderLine->text());
     if(Message == NULL){
         ui->labelTDS->setStyleSheet("background:green;");
         connectCompliteButton = true;
         }
     else ui->LogList->addItem(Message); //вывод в логи
     ui->LogList->addItem(TDS_Device->IDN());

 }
}

void MainWindow::TraceButton(){
    if ( startTrace == false){
        ui->LogList->addItem(TDS_Device->Trace_initial("1", "2500", ui->BoxChannel->currentText(), "ASCII"));
        QList<QString> y_list = TDS_Device->Trace();
        int size_y = y_list.size();
        if(size_y < 10)//ежели будет ошибка по таймауту, то она содержится с 0 QList'е
            ui->LogList->addItem(y_list[0]);//выкидываю эту ошибку в логи
        QVector<double> x(size_y), y;

        double max = y_list.first().toDouble();
        double min = y_list.first().toDouble();
        foreach (const QString str, y_list) {
            y << str.toDouble();
            if(str.toDouble() > max)
                max = str.toDouble();
            if(str.toDouble() < min)
                min = str.toDouble();
        }

        for( double i = 0; i < size_y; i++)
            x[i] = i/10;

        ui->widget->addGraph();
        ui->widget->graph(0)->setData(x,y);
        ui->widget->xAxis->setLabel("time");
        ui->widget->yAxis->setLabel("B");
        ui->widget->xAxis->setRange(0, 250);
        ui->widget->yAxis->setRange(min, max);
        ui->widget->replot();
        startTrace = true;
    }
    else{
        if( mainStateDevice == tds){
        ui->LogList->addItem(TDS_Device->Trace_initial("1", "2500", ui->BoxChannel->currentText(), "ASCII"));
            QList<QString> y_list = TDS_Device->Trace();
            int size_y = y_list.size();
            QVector<double> x(size_y), y;

            double max = y_list.first().toDouble();
            double min = y_list.first().toDouble();
            foreach (const QString str, y_list) {
                y << str.toDouble();
                if(str.toDouble() > max)
                    max = str.toDouble();
                if(str.toDouble() < min)
                    min = str.toDouble();
            }

            for( double i = 0; i < size_y; i++)
                x[i] = i/10;
            ui->widget->yAxis->setRange(min, max);
            ui->widget->graph(0)->setData(x,y);
            ui->widget->replot();
        }

    }
}



void MainWindow::ResetDevice(){

   if(mainStateDevice == tds)
   ui->LogList->addItem(TDS_Device->RST());
   discon_button();

}

