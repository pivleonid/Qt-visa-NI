#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdebug.h"

#include <complex>
#include <vector>
#include <fftw3.h>
using namespace  std;
void func(QVector<complex<double>>& Vec1, QVector<complex<double>>& Vec2, QVector<complex<double> > &Vec3);

MainWindow::MainWindow()
{
//    LeCroy le;
//    qDebug() << le.ConnectDevice("TCPIP0::192.168.70.36::inst0::INSTR");
//    qDebug() << le.WaveFormFormat("OFF","BYTE");
//    QVector<double> wave;
//    le.WaveForm("C1","DAT1",250000000, &wave);
//    qDebug() << le.DisconnectDevice();
    QVector<complex<double>>  Vec1(4000000);
    Vec1[0] = {0, 1};
    Vec1[1] = {1, 1};
    QVector<complex<double>>  Vec2(4000000);
    Vec2[2] = {0, 1};
    Vec2[3] = {1, 1};

    QVector<complex<double>>  Vec3(4000000);

//
    func(Vec1, Vec2, Vec3);
    int u = 1;
}
//=======================================================
MainWindow::~MainWindow()
{

}


void func(QVector<complex<double> >& Vec1, QVector<complex<double>>& Vec2, QVector<complex<double> > &Vec3){

    uint sizeVec1 = Vec1.size();
    uint sizeVec2 = Vec2.size();
    QVector<complex<double> >fftVec1(sizeVec1);
    QVector<complex<double> >fftVec2(sizeVec2);
    fftw_plan plan = fftw_plan_dft_1d(sizeVec1, (fftw_complex*) &Vec1[0], (fftw_complex*) &fftVec1[0], FFTW_FORWARD, FFTW_ESTIMATE);
    fftw_execute(plan);
    plan = fftw_plan_dft_1d(sizeVec2, (fftw_complex*) &Vec2[0], (fftw_complex*) &fftVec2[0], FFTW_FORWARD, FFTW_ESTIMATE);
    fftw_execute(plan);
    //смена знака:
    for(uint i = 0; i < sizeVec2; i++){
        double re = fftVec2[i].real();
        double im = (-1)*fftVec2[i].imag();
        fftVec2[i] = { re, im };
    }
    //перемножение
    uint max = sizeVec1 < sizeVec2 ? sizeVec2 : sizeVec1;
    QVector<complex<double> >fftVec_result(max);
    for(uint i = 0; i < max; i++)
        fftVec_result[i] = fftVec1[i] * fftVec2[i];
    //обратное преобразование
     QVector<complex<double> > ifftw(max);
    plan = fftw_plan_dft_1d(max, (fftw_complex*) &fftVec_result[0], (fftw_complex*) &ifftw[0], FFTW_BACKWARD, FFTW_ESTIMATE);
    fftw_execute(plan);
    for(uint i = 0; i < max; i++){
        double re = (ifftw[i].real())/max;
        double im = (ifftw[i].imag())/max;
        Vec3[i] = { re, im };
        }
    fftw_execute(plan);
    fftw_destroy_plan(plan);
}
