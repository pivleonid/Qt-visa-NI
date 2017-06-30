#include "fsl.h"
#include "qdebug.h"
#include <unistd.h>
//Подразумеваю, что он вызовет конструктор базового класса
FSL::FSL() : BaseDevice()
{

}
/*=========================================================*/
FSL::~FSL(){

}
/*=========================================================*/
QString FSL::centerFreq(const double freq, typeFreq prefix){
  switch (prefix) {
    case GHz: return( WriteCommand("FREQ:CENT " + QString::number(freq) + "GHz") );
    case MHz: return( WriteCommand("FREQ:CENT " + QString::number(freq) + "MHz") );
    case KHz: return( WriteCommand("FREQ:CENT " + QString::number(freq) + "KHz") );
    case Hz:  return( WriteCommand("FREQ:CENT " + QString::number(freq) + "Hz") );

    }
}
/*=========================================================*/
QString FSL::freqSpan(const double span, typeFreq prefix){
  switch (prefix) {
    case GHz: return( WriteCommand("FREQ:SPAN " + QString::number(span) + "GHz") );
    case MHz: return( WriteCommand("FREQ:SPAN " + QString::number(span) + "MHz") );
    case KHz: return( WriteCommand("FREQ:SPAN " + QString::number(span) + "KHz") );
    case Hz:  return( WriteCommand("FREQ:SPAN " + QString::number(span) + "Hz") );

    }

}
/*=========================================================*/
QString FSL::stepCentralFreq( const double step, typeFreq prefix){

  switch (prefix) {
    case GHz: return( WriteCommand("FREQ:CENT:STEP " +  QString::number(step) + "GHz") );
    case MHz: return( WriteCommand("FREQ:CENT:STEP " +  QString::number(step) + "MHz") );
    case KHz: return( WriteCommand("FREQ:CENT:STEP " +  QString::number(step) + "KHz") );
    case Hz:  return( WriteCommand("FREQ:CENT:STEP " +  QString::number(step) + "Hz") );

    }
}
/*=========================================================*/
QString FSL::singleSweep(bool startStop){

    if (startStop == true)
        return( WriteCommand("INIT:CONT ON" ) );
    if (startStop == false )
        return( WriteCommand("INIT:CONT OFF") );
}

/*=========================================================*/
QString FSL::traceData(uint number){

   WriteCommand("TRAC? TRACE1");

    return (ReadDevice(number));
     }
/*=========================================================*/

void FSL::display(bool param){
  if (param == true)
    WriteCommand("SYST:DISP:UPD ON");
  if (param == false)
    WriteCommand("SYST:DISP:UPD OFF");
}
/*=========================================================*/
void FSL::rbw(uint freq){
  WriteCommand( "BAND:RES " + QString::number(freq) );
}

/*=========================================================*/
void FSL::init(){

  qDebug()<< IDN();
  RST(); // по умоляанию включается режим анализатор спектра.
  centerFreq( 500, MHz);
  rbw(100000); //100 KHz
  WriteCommand("DET RMS"); //измеритель среднеквадратического значения



}
/*=========================================================*/

void FSL::calibrate(bool clearSet, const double freq){
  if (clearSet == true){
    freqSpan(10, MHz);
    WriteCommand("FREQ:CENT " + QString::number(freq) + "MHz");
    sleep(1);
    freqSpan(1, MHz);
    WriteCommand("BAND:RES 50 KHz");
    sleep(2);
    freqSpan(100, KHz);
    WriteCommand("BAND:RES 6 KHz");
    sleep(3);
    freqSpan(10, KHz);
    WriteCommand("BAND:RES 600 Hz");
    sleep(4);
    freqSpan(1, KHz);
    WriteCommand("BAND:RES 150 Hz");
    sleep(5);
    }
  else{
     WriteCommand("FREQ:CENT " + QString::number(freq) + "MHz");
     sleep(1);
     freqSpan(1, MHz);
     WriteCommand("BAND:RES 50 KHz");
     sleep(1);
    }
}
