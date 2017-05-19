#ifndef RTO1024_H
#define RTO1024_H
#include <unistd.h>
#include <basedevice.h>

class RTO1024 : public BaseDevice{
public:
    RTO1024() : BaseDevice(){}
    //~RTO1024(){};
    //Инициализация
    QString RTO_init(QString adder){
    ConnectDevice(adder);
    qDebug() << IDN();
    RST();
        WriteCommand("channel1:coupling AC");
        WriteCommand("acquire:mode rtime");
        WriteCommand("acquire:points:maximum 1e8");
        WriteCommand("timebase:range 0.1");
        WriteCommand("acquire:srate 1e8");
        WriteCommand("channel1:range 3");
    }
    //снятие данных
    QString RTO_Data(double N, double F_s, uint32_t number){
    WriteCommand("autoscale");
    WriteCommand("acquire:points:maximum 1e8");
    double range = (1e-3)*((int)(1e3*(N / F_s)));
    WriteCommand("timebase:range " + QString::number(range));// num2str(1e-3*ceil(1e3*N/F_s))]);
    WriteCommand("acquire:srate " + QString::number(F_s ));
    usleep(100);
    WriteCommand("FORM:DATA REAL, 32");
    WriteCommand("CHAN1:DATA?");
    return( ReadDevice(number));

    }
};

#endif // RTO1024_H
