/*==================================================================================*/
/*!
    \brief Класс для работы с осциллографом TDS2024C
    \version 1.0
    \warning Данный класс создан только в учебных целях

    Для соединения и разъединения с прибором использовать функции базового класса:
    ConnectDevice и DisconnectDevice.

    Все методы возвращают строку. Если ошибок нет - нулевую строку.
*/
/*==================================================================================*/
#ifndef TDS2024C_H
#define TDS2024C_H

#include <basedevice.h>
#include <QList>

class TDS2024C : public BaseDevice
{
public:
    TDS2024C();
    ~TDS2024C();
//Настройка прибора:
//Сбор данных: Выборка, Пик. детект. Среднее.
//ACQuire:MODe { SAMple | PEAKdetect | AVErage }
 QString Acquire_mode(QString Mode);
 //Устреднение
 QString Acquire_Averages(QString Averages);
 //OFF | ON | RUN | STOP | <NR1
  QString Acquire_State(QString State);
  //Снятие трейса
/*==================================================================================*/
/*!  \brief
 Метод настройки снятия трейса
\param [in] Start - от 1 до 2500
\param [in] Stop - до 2500
\param [in] Source - { CH{1|2|3|4} | MATH | FFT }
\param [in] Encod - кодировка {ASCIi | RIBinary | RPBinary | SRIbinary | SRPbinary}

\return Строку QString с номером ошибки.
*/
/*==================================================================================*/
  QString Trace_initial(QString Start, QString Stop, QString Source, QString Encod );

/*==================================================================================*/
/*!  \brief
 Метод настройки снятия трейса
\param [in] Start - от 1 до 2500
\param [in] Stop - до 2500
\param [in] Source - { CH{1|2|3|4} | MATH | FFT }
\param [in] Encod - кодировка {ASCIi | RIBinary | RPBinary | SRIbinary | SRPbinary}

\return Строку QString с номером ошибки.
*/
/*==================================================================================*/
  QList<QString> Trace( );



  QString SelectWaveform(QString wfm, QString on_off);
};

#endif // TDS2024C_H
