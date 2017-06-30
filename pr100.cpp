#include "pr100.h"
#include <qdebug.h>
#include <unistd.h>

PR100::PR100() : BaseDevice(){}
PR100::~PR100(){}



void PR100::init(QString adder){


    ConnectDevice(adder);
    AttributesPR100();
    qDebug() << IDN();
    RST();
    sleep(3);
    WriteCommand("system:audio:volume min");
    WriteCommand("display:window \"Spectrum\"");
    WriteCommand("frequency 500 MHz");
    WriteCommand("frequency?");
    qDebug() << "Freq =" + QString(ReadDevice(50));
    WriteCommand("route:path? \"HE-300 500 MHz .. 7 GHz\"");
    QString ANT = ReadDevice(50);
    qDebug() << "ANT = " + ANT;
    ANT = ANT.mid(4,7); // выделяем с 4 по 7 символ
    WriteCommand("route:select " + ANT);

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

void PR100::calibrate(bool clearSet, const double freq){
    if (clearSet == 1){
        WriteCommand("frequency:span 10 MHz");
        WriteCommand("frequency " + QString::number(freq) + " MHz");
        sleep(1);
        WriteCommand("disp:ifp:lev:auto");
        WriteCommand("sense:frequency:afc on");
        sleep(1); //1 сек; usleep(милисек)
        WriteCommand("frequency:span 1 MHz");
        WriteCommand("band 50 kHz");
        sleep(2);
        WriteCommand("frequency:span 100 kHz");
        WriteCommand("band 6 kHz");
        sleep(3);
        WriteCommand("frequency:span 10 kHz");
        WriteCommand("band 600 Hz");
        sleep(4);
        WriteCommand("frequency:span 1 kHz");
        WriteCommand("band 150 Hz");
        sleep(5);
        WriteCommand("sense:frequency:afc off");
        WriteCommand("frequency:span 1 MHz");
        WriteCommand("band 50 kHz");
        WriteCommand("disp:ifp:lev:auto");
        WriteCommand("frequency?");
        qDebug() << "Freq =" + QString(ReadDevice(50));
    }
    else{
        WriteCommand("frequency " + QString::number(freq) + " MHz");
        sleep(1);
        WriteCommand("frequency:span 1 MHz");
        WriteCommand("band 50 kHz");
        WriteCommand("disp:ifp:lev:auto");
        WriteCommand("frequency?");
        qDebug() << "Freq =" + QString(ReadDevice(50));
    }
}


void PR100::setFreq(const double freq){
    WriteCommand("frequency " + QString::number(freq) + "MHz"); //fprintf(PR100_ID,['frequency ' num2str(Freq) ' MHz']);
    usleep(300); //0.3
    WriteCommand("disp:ifp:lev:auto");
    usleep(300);
}
