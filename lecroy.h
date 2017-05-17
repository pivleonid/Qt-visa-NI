#ifndef LECROY_H
#define LECROY_H

#include "basedevice.h"

class LeCroy : public BaseDevice
{
public:
    LeCroy();
    ~LeCroy();
    QString initLectoy(QString adder);
    void DataMeasurement();
/*===========================================*/
/*!  \brief
Инициализация формата данных для снятия трейса
\param [in] blockFormat - DEF9, OFF
\param [in] dataType - BYTE, WORD

\return Строку QString с номером ошибки.
*/
    QString WaveFormFormat(QString blockFormat, QString dataType);
/*===========================================*/
};

#endif // LECROY_H
