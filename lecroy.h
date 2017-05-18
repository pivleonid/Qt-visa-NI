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
/*!  \brief
Снятие трейса?
\param [in] Channel - C1 to Cx, F1 to Fx, M1 to Mx, TA to TD
\param [in] block - DESC (The waveform descriptor); (The user text) TEXT;
The time descriptor (TIME); The data block (DAT1); An optional second data block (DAT2)

\return Строку QString .
*/
    QString WaveForm(QString Channel, QString block);
/*===========================================*/
/*!  \brief
Строка с настройками, которую можно использовать в параметрах снятия трейса
\return Строку QString .
*/
    QString Template();
/*===========================================*/
/*!  \brief
    передача файла
\param [in] Channel - C1 to Cx, F1 to Fx, M1 to Mx, TA to TD
\param [in] logical_block - TRIGTIME,RISTIME,SIMPLE,DATA_ARRAY_1,DATA_ARRAY_2
                            или результат Template();
\param [in] dataType - BYTE, WORD, FLOAT

\return Строку QString .
*/
    QString Trace(QString Channel, QString logical_block, QString dataType);
/*===========================================*/
};

#endif // LECROY_H
