#ifndef LECROY_H
#define LECROY_H

#include "basedevice.h"
#include <complex>
#include <QVector>
class LeCroy : public BaseDevice
{
public:
    LeCroy();
    ~LeCroy(){}
/*===========================================*/
/*!  \brief
    Первичная инициализация Lecroy
\param [in] adder - адрес прибора

\return Строку QString с номером ошибки.
*/
    QString initLectoy(QString adder);
/*===========================================*/
/*!  \brief
Инициализация формата данных для снятия трейса
\param [in] blockFormat - DEF9, OFF
\param [in] dataType - BYTE (8 бит), WORD (16 бит)

\return Строку QString с номером ошибки.
*/
    QString WaveFormFormat(QString blockFormat, QString dataType);
/*===========================================*/
/*!  \brief
Снятие трейса

\param [in] Channel - C1 to Cx, F1 to Fx, M1 to Mx, TA to TD
\param [in] block - DESC (The waveform descriptor); (The user text) TEXT;
The time descriptor (TIME); The data block (DAT1); An optional second data block (DAT2)
\param [in] number - количество данных
\param [out] *waveVecDouble - Уровень сигнала в Вольтах
\param [in] TimeDel - Время на деление. По умолчанию 5 микросек/деление. [KS,S,MS,US,NS]
*/
    void WaveForm(QString Channel, QString block, uint number, QString TimeDel = "10.0E-3");
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
                            или результат Template(); Vertical_gain, Vertical_offset
                             и другое, смотри документацию
\param [in] dataType - BYTE, WORD, FLOAT

\return Строку QString .
*/
    QString INSPECT(QString Channel, QString logical_block, QString dataType);
/*===========================================*/


 /*===========================================================================*/
};


#endif // LECROY_H


//MSIZ - 1e6 //количество отсчетов
//TDIV - 1e-3
