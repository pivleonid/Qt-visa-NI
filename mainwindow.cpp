#include "mainwindow.h"
//#include "ui_mainwindow.h"
#include "qdebug.h"

#include <complex>
#include <vector>
#include <fftw3.h>
using namespace  std;
void func(QVector<complex<double>>& Vec1, QVector<complex<double>>& Vec2, QVector<complex<double> > &Vec3);
void initialMatrix( );
MainWindow::MainWindow()
{


//    LeCroy le;
//    qDebug() << le.ConnectDevice("TCPIP0::192.168.70.36::inst0::INSTR");
//    qDebug() << le.WaveFormFormat("OFF","BYTE");
//   // QVector<float> wave(200000000);

//    le.WaveForm("C1","DAT1",10000000);
//    le.WaveForm("C1","DAT1",250000000);
//  //  le.WaveForm("C1","DAT1",100000000, &wave);
//   // le.WaveForm("C1","DAT1",100000000, &wave);
//   // le.WaveForm("C1","DAT1",100000000, &wave);
//   // le.WaveForm("C1","DAT1",100000000, &wave);
//    qDebug() << le.DisconnectDevice();

//    QVector<complex<double>>  Vec1(10000000);
//    Vec1[0] = {0, 1};
//    Vec1[1] = {1, 1};

//    QVector<complex<double>>  Vec2(10000000);
//    Vec2[0] = {0, 1};
//    Vec2[1] = {1, 1};
//    QVector<complex<double>>  Vec3(10000000);
////
//    func(Vec1, Vec2, Vec3);
    //
   // int* matrixCalibate;
    initialMatrix( );
    //delete [10000] matrixCalibate;

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
    fftw_destroy_plan(plan);
}


void initialMatrix( ){
  const int x = 10;
  const int y = 10;
  const  int x1 = 4;
  const int y1 = 4;
  complex<double> matrixCalibate[x][y];
  complex<double>* ptr;
  complex<double> matrixCalibateOut[x][y];
  complex<double>* ptr2;
  for(int i = 0; i < x ; i++){
      for(int j = 0; j < y; j++)
          matrixCalibate[i][j] = 1;
  }

  for(int i = 0; i < (x - x1) ; i++){
      for(int j = 0; j < (y - y1); j++)
          matrixCalibate[i][j] = 0;
  }
  ptr = *matrixCalibate;
  ptr2 = *matrixCalibateOut;
  fftw_plan plan = fftw_plan_dft_2d(x, y, (fftw_complex*)ptr, (fftw_complex*)ptr2,FFTW_FORWARD, FFTW_ESTIMATE);
  fftw_execute(plan);
  int c;
}
