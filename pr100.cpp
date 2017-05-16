#include "pr100.h"
#include <qdebug.h>
#include <QtTest/qtest.h>

PR100::PR100() : BaseDevice(){}
PR100::~PR100(){}



void PR100::initFirst(QString adder){


    ConnectDevice(adder);
    qDebug() << IDN();
    RST();
    WriteCommand("system:audio:volume min");
    WriteCommand("display:window \"Spectrum\"");
    WriteCommand("frequency 500 MHz");
    WriteCommand("frequency?");
    qDebug() << "Freq =" + QString(ReadDevice(50));
    WriteCommand("route:path? \"HE-300 500 MHz .. 7 GHz\"");
    qDebug() << "ANT =" + QString(ReadDevice(50));;

    //WriteCommand("route:path? \"HE-300 500 MHz .. 7 GHz\"");
    //qDebug() << "ANT =" + QString(ReadDevice(50));
    ///fprintf(PR100_ID,['route:select ' ANT(4:7)]);
    ///
    WriteCommand("band max");
    WriteCommand("band?");
    qDebug() << "band =" + QString(ReadDevice(50));
    WriteCommand("detector rms");
    WriteCommand("disp:ifp:lev:auto");
    WriteCommand("disp:ifp:lev:ref?");
    qDebug() << "disp =" + QString(ReadDevice(50));
    WriteCommand("det?");
    qDebug() << "det =" + QString(ReadDevice(50));
    WriteCommand("sense:corr:ant act");
    WriteCommand("sense:func:on \"VOLT:AC\"");
    WriteCommand("sense:data? \"VOLT:AC\"");
    qDebug() << "AC =" + QString(ReadDevice(50));
    WriteCommand("output:if:state?");
    qDebug() << "IF state =" + QString(ReadDevice(50));
    WriteCommand("input:attenuation:state?");
    qDebug() << "input:attenuation:state =" + QString(ReadDevice(50));
    WriteCommand("sense:frequency:afc?");
    qDebug() << "AFC =" + QString(ReadDevice(50));


}

void PR100::Calibrate(bool ClearSet){
    if (ClearSet == 1){
        WriteCommand("frequency:span 10 MHz");
        //fprintf(PR100_ID,['frequency ' num2str(Frequency) ' MHz']);
        WriteCommand("disp:ifp:lev:auto");
        WriteCommand("sense:frequency:afc on");
        QTest::qSleep(1000);
        WriteCommand("frequency:span 1 MHz");
        WriteCommand("band 50 kHz");
        QTest::qSleep(2000);wwwwwr
        WriteCommand("frequency:span 100 kHz");
        WriteCommand("band 6 kHz");
        QTest::qSleep(3000);
        WriteCommand("frequency:span 10 kHz");
        WriteCommand("band 600 Hz");
        QTest::qSleep(4000);
        WriteCommand("frequency:span 1 kHz");
        WriteCommand("band 150 Hz");
        QTest::qSleep(5000);
        WriteCommand("sense:frequency:afc off");
        WriteCommand("frequency:span 1 MHz");
        WriteCommand("band 50 kHz");
        WriteCommand("disp:ifp:lev:auto");
        WriteCommand("frequency?");
        ///Freq = str2double(fscanf(PR100_ID));
        qDebug() << "Freq =" + QString(ReadDevice(50));
    }
    else{
        //fprintf(PR100_ID,['frequency ' num2str(Frequency) ' MHz']); pause(1);
        WriteCommand("frequency:span 1 MHz");
        WriteCommand("band 50 kHz");
        WriteCommand("disp:ifp:lev:auto");
        WriteCommand("frequency?");
        ///    Freq = str2double(fscanf(PR100_ID));
        qDebug() << "Freq =" + QString(ReadDevice(50));
    }
}


void PR100::setFreq(QString Freq){
    WriteCommand("frequency " + Freq + "MHz"); //fprintf(PR100_ID,['frequency ' num2str(Freq) ' MHz']);
    QTest::qSleep(300); //0.3
    WriteCommand("disp:ifp:lev:auto");
    QTest::qSleep(300);
}