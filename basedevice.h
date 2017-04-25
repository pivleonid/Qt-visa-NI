#ifndef BASEDEVICE_H
#define BASEDEVICE_H
#include <visa.h>
#include <visatype.h>
#include <memory.h>
#include <QString>
#include <QMap>

class BaseDevice
{

public:
    BaseDevice();
    ~BaseDevice();
    //typeConnect = TCPIP; typeAdder = 192.168.70.39
    QString ConnectDevice(QString typeConnect, QString typeAdder );
    QString DisconnectDevice( );
    QString IDN();
    QString RST();
    QString TST();
    QString WAI();
    QString ErrorFunction(ViStatus status);
protected:
    bool flag_connect;
private:
    ViSession	rm, vi;
    ViStatus	status;
    ViChar		buffer[256];
    ViUInt32	retCnt;
    QMap<int, QString> ErrorList;
};

#endif // BASEDEVICE_H
