#include "lecroy.h"
#include "qdebug.h"

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

void LeCroy::DataMeasurement(){


}

QString LeCroy::WaveFormFormat(QString blockFormat, QString dataType){
    return(WriteCommand("COMM_FORMAT " + blockFormat + "," + dataType + ",BIN"));

}


QString LeCroy::WaveForm(QString Channel, QString block, qint32 number){
    WriteCommand("MSIZ " + QString::number(number) );
    WriteCommand(Channel + ":WF? " + block);
    QByteArray waveDat = ReadDevice_Array(number);
    //
    WriteCommand("C1:INSPECT? Vertical_gain");
    QString VGain = ReadDevice(50);
     VGain =  VGain.mid(30,45); // выделяем с 4 по 7 символ
    //
    WriteCommand("C1:INSPECT? Vertical_offset");
    QString VOffset = ReadDevice(50);
    VOffset =  VOffset.mid(30,45);
    // далее из строк получить данные типа double
    // wavedat[i] = wavedat[i] * VGain - VOffset;

    return "Hello kitty" ;
}

QString LeCroy::Template(){
    WriteCommand("TEMPLATE?");
    return(ReadDevice(100));
}

QString LeCroy::INSPECT(QString Channel, QString logical_block, QString dataType){
    WriteCommand(Channel + ":INSPECT? " + logical_block + ", " + dataType);
}


