#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImage>
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

            scene = new QGraphicsScene(this);
            ui->graphicsView->setScene(scene);

        vector<complex<double> > data(10000);
        data[0] = {1 , 0};
        data[1] = {1 , 0};
        //
        data[10] = {1 , 0};
        data[11] = {1 , 0};

        vector<complex<double> > data_out1(10000);
        vector<complex<double> > data_out2(10000);
// создаем план для библиотеки fftw
//(FFTW_FORWARD - прямое, FFTW_BACKWARD - обратное)
//   fftw_plan plan=fftw_plan_dft_1d(data.size(), (fftw_complex*) &data[0], (fftw_complex*) &data_out1[0], FFTW_FORWARD, FFTW_ESTIMATE);

   fftw_plan plan=fftw_plan_dft_2d(100,100, (fftw_complex*) &data[0], (fftw_complex*) &data_out1[0], FFTW_FORWARD, FFTW_ESTIMATE);

   // преобразование Фурье
   fftw_execute( plan);

   fftw_destroy_plan( plan);

   // выводим в файл результат преобразования Фурье (должна получиться Дельта-функция)

   double maxV = -99999;
   double minV = 99999;
   double temp;
   uchar *mas = new uchar[10000];
   QList<double> tempList;
   for(size_t i=0; i<data.size(); i++)
   {
      temp = sqrt(data_out1[i].real()*data_out1[i].real() + data_out1[i].imag()*data_out1[i].imag());
      qDebug() << temp;
      if (maxV<temp ) maxV = temp;
      if (minV>temp ) minV = temp;
      tempList.append(temp);
   }
   for(size_t i=0; i<data.size(); i++)
   {
      double temp = tempList.at(i);
      double ttt = (temp-minV)/(maxV-minV)*255.0;
      mas[i]=ttt;
   }



    QImage img( mas, 100, 100,  QImage::Format_Indexed8);
    QPixmap *pixmap = new QPixmap(QPixmap::fromImage(img));
    scene->addPixmap(QPixmap::fromImage(img));
    pixmap->save("filename.png", "PNG");

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

