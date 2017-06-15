#include "mainwindow.h"
//#include "ui_mainwindow.h"
#include "qdebug.h"

#include <complex>
#include <vector>
#include <fftw3.h>

#include "pr100.h"
//=======================================================
using namespace  std;
void func(QVector<complex<double>>& Vec1, QVector<complex<double>>& Vec2, QVector<complex<double> > &Vec3);
void initialMatrix( int x, int x1, int y, int y1, QVector<complex<double>>& matrixCalibate );
void AndreyOperation( int x, int y, QVector<complex<double>>& imageMatrix, QVector<complex<double>>& matrixCalibate, int &indx, int &indy);
//=======================================================
MainWindow::MainWindow()
{
    PR100 Pr;

    Pr.init("TCPIP0::192.168.70.42::5555::SOCKET");
    Pr.calibrate(true, 500);
    Pr.setFreq(100);


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
void AndreyOperation( int x, int y, QVector<complex<double>>& imageMatrix, QVector<complex<double>>& matrixCalibate, int &indx, int &indy){

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
        for (int a = 0; a < y; a++)
            for(int b = 0; b < x; b++){
                int n = a * x + b;
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
