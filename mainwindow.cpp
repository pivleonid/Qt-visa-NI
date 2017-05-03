#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //
      TDS2024C TDS;
        QString b;
        b = TDS.ConnectDevice("USB0", "0x0699::0x03A6::C011549");
        b = TDS.IDN();
        b = TDS.Trace_initial("1", "2500", "CH1", "ASCII");
        QList<QString> y_list = TDS.Trace();
        int size_y = y_list.size();
        QVector<double> x(size_y), y;
        double max = 0;
        double min = 0;
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
        ui->widget->xAxis->setLabel("x");
        ui->widget->yAxis->setLabel("y");
        ui->widget->xAxis->setRange(0, 250);
        ui->widget->yAxis->setRange(min, max);
        ui->widget->replot();
}

MainWindow::~MainWindow()
{
    delete ui;
}
