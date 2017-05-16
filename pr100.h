/*=============================================================================================================*/
/*!
    \brief Класс для работы с приемником PR100
    \version 1.0

    Для соединения и разъединения с прибором использовать функции базового класса:
    ConnectDevice и DisconnectDevice.

*/
/*=============================================================================================================*/
#ifndef PR100_H
#define PR100_H

#include <basedevice.h>

class PR100 : public BaseDevice
{
public:
    PR100();
    ~PR100();
    void initFirst(QString adder);
    void Calibrate(bool ClearSet);
    void setFreq(QString Freq);
};

#endif // PR100_H
