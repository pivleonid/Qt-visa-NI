#include "fsl.h"
//Подразумеваю, что он вызовет конструктор базового класса
FSL::FSL() : BaseDevice()
{

}
/*=========================================================*/
FSL::~FSL(){

}
/*=========================================================*/
QString FSL::CenterFreq(QString Freq, QString prefix){
   return( WriteCommand("FREQ:CENT " + Freq + prefix) );
}

/*=========================================================*/
QString FSL::FreqSpan(QString Span, QString prefix){
   return( WriteCommand("FREQ:SPAN " + Span + prefix) );
}
/*=========================================================*/
QString FSL::StepCentralFreq(QString Step, QString prefix){
   return( WriteCommand("FREQ:CENT:STEP " + Step + prefix) );
}
/*=========================================================*/
QString FSL::SingleSweep(bool StartStop){

    if (StartStop == true)
        return( WriteCommand("INIT:CONT ON" ) );
    if (StartStop == false )
        return( WriteCommand("INIT:CONT OFF") );
}

/*=========================================================*/
QString FSL::TRACeData(){
QString a;
    a =  WriteCommand("TRAC? TRACE1");
    a =  ReadDevice( 20000);
    return a;
     }
