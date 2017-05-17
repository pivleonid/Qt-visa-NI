#include "lecroy.h"
#include "qdebug.h"

LeCroy::LeCroy():BaseDevice()
{

}

QString LeCroy::initLectoy(QString adder){

    ConnectDevice(adder);
    qDebug() << IDN();
    RST();
    WriteCommand("DD_READGATE_CHANNEL C1");
    WriteCommand("C1:COUPLING A1M");
        WriteCommand("C1:COUPLING?");
        qDebug() << ReadDevice(50);


    WriteCommand("C1:VOLT_DIV 10MV"); //Сколько клеток на осцил?
    WriteCommand("DOT_JOIN OFF"); //измерение без интерполяции
    WriteCommand("TIME_DIV 2E-3"); //2мс на деление

        return(IDN());
}


void LeCroy::DataMeasurement(){


}

QString LeCroy::WaveFormFormat(QString blockFormat, QString dataType){
    return(WriteCommand("COMM_FORMAT " + blockFormat + "," + dataType + "BIN"));
}