/*==================================================================*/
/*!
    \brief Базовый класс связки с приборами через библиотеку visa
    \version 1.0
    \warning Данный класс создан только в учебных целях

    Обычный базовый класс для работы с приборами.
    Все методы возвращают строку. Если ошибок нет - нулевую строку.
*/
/*==================================================================*/
#ifndef BASEDEVICE_H
#define BASEDEVICE_H

#ifndef LINUXBASE


#include <visa.h>
#include <visatype.h>
#include <memory.h>
#include <QString>
#include <QMap>
#include <QByteArray>


class BaseDevice
{

public:
/*==================================================================*/
//! Конструктор.
/*!
 * Инициализация ErrorList значениями, очистка буфера, Visa параметров,
 * отвечающих за подклчение к прибору. Установка флага flag_connect.
 *
 * У Андрея за запись/чтение строки, тип double, отвечает printf/scanf
 * Чтение строки в виде буфера и массива viRead.
 */
    BaseDevice();
    ~BaseDevice();
/*==================================================================*/
/*!  \brief
 Метод для стыковки с прибором
\param [in] typeConnect - тип соединения:USB, TCPIP, GPIB
\param [in] typeAdder - адрес. Для TCPIP это: 192.168.70.39
\return Строку QString. Ежели строка пустая- Успешное выполнение команды,
 нет- читаем.
*/
    enum typeConnect{
      USB,
      TCPIP,
      GPIB
    }tC;

    QString ConnectDevice( typeConnect tC , QString typeAdder );

/*==================================================================*/
/*!  \brief
 Метод для стыковки с прибором
\param [in] Connect - Прописывается адрес всего соединения
\return Строку QString. Ежели строка пустая- Успешное выполнение команды, нет- читаем.
*/

    QString ConnectDevice(QString Connect );

/*==================================================================*/
/*!  \brief
 Метод для рассоединения с прибором
\return  Строку QString. Ежели строка пустая- Успешное выполнение команды, нет- читаем.
*/

    QString DisconnectDevice( );


///Базовые функции. Возвращают  QString. Ежели строка пустая- Успешное выполнение команды, нет- читаем.

    QString IDN();
    QString RST();
    QString TST();
    QString WAI();
    QString OPC();
    QString BUSY();

    //Функция получения номера сессии
    ViSession GetSesion(){
        return(vi);
    }


protected:

    bool flag_connect;  ///<    Флаг проверки подключения прибора
/*==================================================================*/
/*!  \brief
 Метод поиска описания ошибки. Ежели такой нет, то на выходе будет номер.
\param [in] status(переменная типа ViStatus)
\return Строку QString с номером ошибки.
*/

    QString ErrorFunction(ViStatus status);

/*==================================================================*/
/*!  \brief
 Универсальная функция для записи в прибор. Использует viWrite.
\param [in] command - строковая команда, согласно документации на прибор
\return Строку QString. Ежели строка пустая- Успешное выполнение команды, нет- читаем.
*/

    QString WriteCommand(QString command);

/*==================================================================*/
/*!  \brief
        Универсальная функция для чтения из прибора. Использует viRead.
\param  [in] count - Количество символов для чтения
\return Строку QString. Ежели строка пустая- Успеш,kzное выполнение команды, нет- читаем.
*/

    QString ReadDevice(  uint count );
/*==================================================================*/
/*!  \brief
        Универсальная функция для чтения из прибора. Использует viRead.
\param  [in] count - Количество символов для чтения
\return QByteArray - (-1) == Не выполнена функция ConnectDevice
                   - (-2) == Ошибка не определена
*/
QByteArray ReadDevice_Array( uint count);



/*==================================================================*/
private:


/*types/*============================================================*/
    ViSession	rm, vi;
    ViStatus	status;
    ViUInt32	retCnt;
    QMap<int, QString> ErrorList;
};

#endif

#ifdef LINUXBASE

#include "QDebug"

#include <../../Загрузки/vxi11_1.10/vxi11_user.h>

#define BUF_LEN 100000

class BaseDevice
{

CLINK* link_;
bool flagConnect_;
int ret_;
//нужен для закрытия соединения
QString deviceIp;
public:
BaseDevice();
~BaseDevice();
CLINK* getLink(){
return link_;
}
//обычно deviceName = inst0
//ежели возвращаемое значение != 0, то ошибка
QString connectDevice( QString ip, QString deviceName);
QString connectDevice(QString ip);
QString disconnectDevice();

//Шаблонные базовые команды
QString IDN();
QString RST();
QString TST();
QString WAI();
QString OPC();
QString BUSY();

QString writeCommand(QString command);
QString readDevice(const int count); //сколько символов принять
QString writeAndRead(QString command, const int count);
void readDevice_Array(const int count, QByteArray& readData);
};


#endif

#endif // BASEDEVICE_H
