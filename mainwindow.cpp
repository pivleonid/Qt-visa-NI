#include "mainwindow.h"
//#include "ui_mainwindow.h"
#include "qdebug.h"

#include <complex>
#include <vector>
#include <fftw3.h>

#include "pr100.h"
#include "lecroy.h"
//=======================================================
using namespace  std;
void func(QVector<complex<double>>& Vec1, QVector<complex<double>>& Vec2, QVector<complex<double> > &Vec3);
void initialMatrix( int x, int x1, int y, int y1, QVector<complex<double>>& matrixCalibate );
void AndreyOperation( uint x, uint y, QVector<complex<double>>& imageMatrix, QVector<complex<double>>& matrixCalibate, uint &indx, uint &indy);
//=======================================================
MainWindow::MainWindow()
{



//  uint x = 10 ;
//  uint y = 10;
//  uint x1 = 5 ;
//  uint y1 = 5;


//  QVector<complex<double>> matrixCalibate;
//  initialMatrix( x, x1 , y, y1 , matrixCalibate);

//  QVector<complex<double>> matrixCalibate1;
//  matrixCalibate1.resize(x * y);
//  for (uint a = 0; a < y; a++)
//      for(uint b = 0; b < x; b++){
//          uint n = a * x + b;
//          matrixCalibate1[n] = 0;
//      }
//  uint nnn = 2;
//  for (uint a = 0; a < y1; a++)
//      for(uint b = 0; b < x ; b++){
//          uint n = ( nnn + a ) * x + b;
//          matrixCalibate1[n] = 1;
//      }
//  nnn = 2;
//  for ( uint a = 0; a < y; a++ )
//      for(uint b = 0; b < x1 ; b++){
//          uint n = a * x + b + nnn;
//          matrixCalibate1[n] = 1;
//      }

//  uint indx;
//  uint indy;
//  AndreyOperation( x,y, matrixCalibate1, matrixCalibate, indx, indy);

//  LeCroy le;
//  qDebug() << le.ConnectDevice("TCPIP0::192.168.70.34::inst0::INSTR");
//  le.WaveForm("C1", "DAT1", 250000000  );
//      int t=0;


//  QVector<double> a1(100);
//  QVector<complex<double>> a2(100);
//  for(uint i = 0; i < 100; i++)
//    a1[i] = 1;
//  fftw_plan plan = fftw_plan_dft_r2c_1d(100,  (double*)&a1[0], (fftw_complex*) &a2[0], FFTW_ESTIMATE  );
//    fftw_execute(plan);
//  fftw_destroy_plan(plan);
//  int b1 = 1;


  PR100 pr;
  pr.init("TCPIP0::192.168.70.42::5555::SOCKET");
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


void initialMatrix( int x, int x1, int y, int y1, QVector<complex<double>>& matrixCalibate ){

    matrixCalibate.resize(x * y);
    for (int a = 0; a < y; a++)
        for(int b = 0; b < x; b++){
            int n = a * x + b;
            matrixCalibate[n] = 1;
        }
    for (int a = 0; a < y - y1; a++)
        for(int b = 0; b < x - x1; b++){
            int n = a * x + b;
            matrixCalibate[n] = 0;
        }
  fftw_plan plan = fftw_plan_dft_2d(x, y, (fftw_complex*)&matrixCalibate[0], (fftw_complex*)&matrixCalibate[0],FFTW_FORWARD, FFTW_ESTIMATE);
  fftw_execute(plan);
  //смена знака:
  for(uint i = 0; i < x*y; i++){
      double re = matrixCalibate[i].real();
      double im = (-1)*matrixCalibate[i].imag();
      matrixCalibate[i] = { re, im };
  }


  fftw_destroy_plan(plan);

}

// x, y  размерность "матрицы"
void AndreyOperation( uint x, uint y, QVector<complex<double>>& imageMatrix, QVector<complex<double>>& matrixCalibate, uint &indx, uint &indy){

    fftw_plan plan = fftw_plan_dft_2d(x, y, (fftw_complex*)&imageMatrix[0], (fftw_complex*)&imageMatrix[0],FFTW_FORWARD, FFTW_ESTIMATE);
    fftw_execute(plan);
    for(uint i = 0; i < x*y; i++)
    {
        imageMatrix[i] = imageMatrix[i] * matrixCalibate[i];
    }

        plan = fftw_plan_dft_2d(x, y, (fftw_complex*)&imageMatrix[0], (fftw_complex*)&imageMatrix[0],FFTW_BACKWARD, FFTW_ESTIMATE);
        fftw_execute(plan);
        fftw_destroy_plan(plan);

        double matrixMax;
        double temp = 0;
        indx = -1;
        indy = -1;
        //операция взятия по модулю
        for (uint a = 0; a < y; a++)
            for(uint b = 0; b < x; b++){
                uint n = a * x + b;
                double re = imageMatrix[n].real();
                double im = imageMatrix[n].imag();
                matrixMax = sqrt(re*re + im*im);
                if(matrixMax > temp){
                    indx = b;
                    indy = a;
                    temp = matrixMax;
                }
            }
}
