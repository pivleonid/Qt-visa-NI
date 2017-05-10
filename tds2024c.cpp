#include "tds2024c.h"
/*=========================================================*/
TDS2024C::TDS2024C() : BaseDevice()
{

}
/*=========================================================*/
TDS2024C::~TDS2024C(){

}
/*=========================================================*/
QString TDS2024C::Acquire_mode(QString Mode){
   return( WriteCommand("ACQuire:MODe " + Mode) );
}
/*=========================================================*/
QString TDS2024C::Acquire_Averages(QString Averages){
    return( WriteCommand("ACQuire:NUMAVg " + Averages) );
}
/*=========================================================*/
QString TDS2024C::Acquire_State(QString State){
    return( WriteCommand("ACQuire:NUMAVg " + State) );
}
/*=========================================================*/
QString TDS2024C::Trace_initial(QString Start, QString Stop, QString Source, QString Encod){
    QString ErrorMessage;
    ErrorMessage = WriteCommand("DATa:ENCdg " + Encod);
    if(ErrorMessage != NULL)
        return(ErrorMessage);
    while((BUSY().toInt())){};
    ErrorMessage = WriteCommand("DATa:SOUrce " + Source);
    if(ErrorMessage != NULL)
        return(ErrorMessage);
    while((BUSY().toInt())) {};
    ErrorMessage = WriteCommand("DATa:STARt " + Start);
    if(ErrorMessage != NULL)
        return(ErrorMessage);
    while((BUSY().toInt())){};
    ErrorMessage = WriteCommand("DATa:STOP " + Stop);
    if(ErrorMessage != NULL)
        return(ErrorMessage);
    while((BUSY().toInt())){};
    return(ErrorMessage);
}
/*=========================================================*/
QList<QString> TDS2024C::Trace(){
    QString Message;
    Message =  WriteCommand("CURVE?");
    if(Message == NULL)
       Message = ReadDevice(40000);
    QList<QString> list_data = Message.split(',');
    //Последний символ типа '16/n' /n надо убрать
    QString data_list = list_data.last();
    data_list = data_list.left(data_list.length() - 1);
    list_data.last() = data_list;
    return (list_data);
}

/*=========================================================*/

QString TDS2024C::SelectWaveform(QString wfm, QString on_off){
QString Message;
Message = WriteCommand("SELect:"+wfm+" "+on_off);
}
