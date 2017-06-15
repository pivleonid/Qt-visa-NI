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
    WriteCommand("system:audio:volume min\n");
    WriteCommand("display:window \"Spectrum\"\n");
    WriteCommand("frequency 500 MHz\n");
    WriteCommand("frequency?\n");
    qDebug() << "Freq =" + QString(ReadDevice(50));
    WriteCommand("route:path? \"HE-300 500 MHz .. 7 GHz\"\n");
    QString ANT = ReadDevice(50);
    qDebug() << "ANT = " + ANT;
    ANT = ANT.mid(4,7); // выделяем с 4 по 7 символ
    WriteCommand("route:select " + ANT +"\n");

    WriteCommand("band max\n");
    WriteCommand("band?\n");
    qDebug() << "band =" + QString(ReadDevice(50));
    WriteCommand("detector rms\n");
    WriteCommand("disp:ifp:lev:auto\n");
    WriteCommand("disp:ifp:lev:ref?\n");
    qDebug() << "disp =" + QString(ReadDevice(50));
    WriteCommand("det?\n");
    qDebug() << "det =" + QString(ReadDevice(50));
    WriteCommand("sense:corr:ant act\n");
    WriteCommand("sense:func:on \"VOLT:AC\"\n");
    WriteCommand("sense:data? \"VOLT:AC\"\n");
    qDebug() << "AC =" + QString(ReadDevice(50));
    WriteCommand("output:if:state?\n");
    qDebug() << "IF state =" + QString(ReadDevice(50));
    WriteCommand("input:attenuation:state?\n");
    qDebug() << "input:attenuation:state =" + QString(ReadDevice(50));
    WriteCommand("sense:frequency:afc?\n");
    qDebug() << "AFC =" + QString(ReadDevice(50));


}

void PR100::calibrate(bool clearSet, const double freq){
    if (clearSet == 1){
        WriteCommand("frequency:span 10 MHz\n");
        WriteCommand("frequency " + QString::number(freq) + " MHz\n");
        sleep(1);
        WriteCommand("disp:ifp:lev:auto\n");
        WriteCommand("sense:frequency:afc on\n");
        sleep(1); //1 сек; usleep(милисек)
        WriteCommand("frequency:span 1 MHz\n");
        WriteCommand("band 50 kHz\n");
        sleep(2);
        WriteCommand("frequency:span 100 kHz\n");
        WriteCommand("band 6 kHz\n");
        sleep(3);
        WriteCommand("frequency:span 10 kHz\n");
        WriteCommand("band 600 Hz\n");
        sleep(4);
        WriteCommand("frequency:span 1 kHz\n");
        WriteCommand("band 150 Hz\n");
        sleep(5);
        WriteCommand("sense:frequency:afc off\n");
        WriteCommand("frequency:span 1 MHz\n");
        WriteCommand("band 50 kHz\n");
        WriteCommand("disp:ifp:lev:auto\n");
        WriteCommand("frequency?\n");
        qDebug() << "Freq =" + QString(ReadDevice(50));
    }
    else{
        WriteCommand("frequency " + QString::number(freq) + " MHz\n");
        sleep(1);
        WriteCommand("frequency:span 1 MHz\n");
        WriteCommand("band 50 kHz\n");
        WriteCommand("disp:ifp:lev:auto\n");
        WriteCommand("frequency?\n");
        qDebug() << "Freq =" + QString(ReadDevice(50));
    }
}


void PR100::setFreq(const double freq){
    WriteCommand("frequency " + QString::number(freq) + "MHz\n"); //fprintf(PR100_ID,['frequency ' num2str(Freq) ' MHz']);
    usleep(300); //0.3
    WriteCommand("disp:ifp:lev:auto\n");
    usleep(300);
}
