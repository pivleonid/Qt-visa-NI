/*!
    \brief Базовый класс связки с приборами через библиотеку visa
    \version 1.0
    \warning Данный класс создан только в учебных целях

    Обычный базовый класс для работы с приборами.
    Все методы возвращают строку. Если ошибок нет - нулевую строку.
*/

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
//! Конструктор.
/*!
 * Инициализация ErrorList значениями, очистка буфера, Visa параметров,
 *  отвечающих за подклчение к прибору. Установка флага flag_connect.
 */
    BaseDevice();
    ~BaseDevice();
/*=============================================================================================================*/
/*!  \brief
 Метод для состыковки с прибором
\param [in] typeConnect - тип соединения: TCPIP
\param [in] typeAdder - адрес. Для TCPIP это: 192.168.70.39
\return Строку QString. Ежели строка пустая- Успешное выполнение команды, нет- читаем.
*/
/*=============================================================================================================*/
    QString ConnectDevice(QString typeConnect, QString typeAdder );
    QString DisconnectDevice( );
    QString IDN();
    QString RST();
    QString TST();
    QString WAI();
protected:
    bool flag_connect;
/*=============================================================================================================*/
/*!  \brief
 Метод поиска описания ошибки. Ежели такой нет, то на выходе будет номер.
\param [in] status(переменная типа ViStatus)
\return Строку QString с номером ошибки.
*/
/*=============================================================================================================*/
    QString ErrorFunction(ViStatus status);
private:
    ViSession	rm, vi;
    ViStatus	status;
    ViChar		buffer[256];
    ViUInt32	retCnt;
    QMap<int, QString> ErrorList;
};

#endif // BASEDEVICE_H
