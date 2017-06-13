#include "lecroy.h"
#include "qdebug.h"
#include <qfile.h>

LeCroy::LeCroy():BaseDevice()
{

}

QString LeCroy::initLectoy(QString adder){

    ConnectDevice(adder);
    qDebug() << IDN();
    RST();
    WriteCommand("C1:TRA ON");
    WriteCommand("C2:TRA OFF");
    WriteCommand("C3:TRA OFF");
    WriteCommand("C4:TRA OFF");
    //WriteCommand("DD_READGATE_CHANNEL C1");
    WriteCommand("C1:COUPLING A1M");
        WriteCommand("C1:COUPLING?");
        qDebug() << ReadDevice(50);



    WriteCommand("C1:VOLT_DIV 10MV"); //Сколько клеток на осцил?  +
    WriteCommand("DOT_JOIN OFF"); //измерение без интерполяции
    WriteCommand("TIME_DIV 2E-3"); //2мс на деление

        return(IDN());
}



QString LeCroy::WaveFormFormat(QString blockFormat, QString dataType){
    return(WriteCommand("COMM_FORMAT " + blockFormat + "," + dataType + ",BIN"));

}


void LeCroy::WaveForm( QString Channel, QString block, uint number,  QString TimeDel ){
    WriteCommand("TIME_DIV " + TimeDel );
    WriteCommand("MSIZ " + QString::number(number) );
    WriteCommand(Channel + ":WF? " + block);
    QByteArray waveDat = ReadDevice_Array(number + 22);/*
    WriteCommand("C1:INSPECT? Vertical_gain");
    QString VGain = ReadDevice(50);
    VGain =  VGain.mid(30,15);
    double Vgain = VGain.toDouble();
    WriteCommand("C1:INSPECT? Vertical_offset");
    QString VOffset = ReadDevice(50);
    VOffset =  VOffset.mid(30,15);
    double Voffset = VOffset.toDouble();
   for(uint i = 22, j = 0; i < number+22; i++, j++ ){
       float count = waveDat[i] * Vgain - Voffset;
       waveVecDouble[j] = count;
   }*/
    int i = 0;
}

QString LeCroy::Template(){
    WriteCommand("TEMPLATE?");
    return(ReadDevice(100));
}

QString LeCroy::INSPECT(QString Channel, QString logical_block, QString dataType){
    WriteCommand(Channel + ":INSPECT? " + logical_block + ", " + dataType);
}


