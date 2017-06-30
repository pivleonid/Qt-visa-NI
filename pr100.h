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
    /*========================================================*/
    /*!  \brief
    Функция инициализации прибора
    \param [in] adder- полный адрес прибора "TCPIP0::192.168.70.42::5555::SOCKET"
    \return
    */
     void init(QString adder);

    /*========================================================*/
    /*!  \brief
    Функция калибровки
    \param [in] clearSet - флаг
    \param [in] clearSet - частота в МГц
    \return
    */
    void calibrate(bool clearSet, const double freq);

    /*========================================================*/
    /*!  \brief
    Установка шага центральной частоты
    \param [in] freq - частота в МГц
    \return
    */
    void setFreq(const double freq);

    /*========================================================*/
    void AttributesPR100(void ){
        ViSession vi = GetSesion();
        viSetAttribute(vi,VI_ATTR_SUPPRESS_END_EN, VI_FALSE);
    }
    QString IDN(){

        WriteCommand("*idn?\n");
        return(ReadDevice(50));
    }

    QString RST(){
        return (WriteCommand("*rst\n"));
    }
    QString WAI(){
        return (WriteCommand("*wai\n"));
    }


};

#endif // PR100_H
