#include "basedevice.h"

BaseDevice::BaseDevice()
{
//    outBuffer = new QString();
    rm = VI_NULL;
    vi = VI_NULL;
    flag_connect = false;
    //Заполнение словаря
    {
    //Заполнение словаря
    //viOpenDefaultRM();
        ErrorList[VI_ERROR_SYSTEM_ERROR] = "The VISA system failed to initialize.";
        ErrorList[VI_ERROR_ALLOC] = "Insufficient system resources to create a session to the Default Resource Manager resource";
        ErrorList[VI_ERROR_INV_SETUP] = "Some implementation-specific configuration file is corrupt or does not exist";
        ErrorList[VI_ERROR_LIBRARY_NFOUND] = "A code library required by VISA could not be located or loaded";
        //viOpen();
        ErrorList[VI_ERROR_INV_OBJECT] = "The given session reference is invalid.";
        ErrorList[VI_ERROR_NSUP_OPER] = "The given sesn does not support this operation. This operation is supported only by a Resource Manager session.";
        ErrorList[VI_ERROR_INV_RSRC_NAME] = "Invalid resource reference specified. Parsing error.";
        ErrorList[VI_ERROR_INV_ACC_MODE] = "Invalid access mode.";
        ErrorList[VI_ERROR_RSRC_NFOUND] = "Insufficient location information or resource not present in the system.";
        ErrorList[VI_ERROR_ALLOC] = "Insufficient system resources to open a session.";
        ErrorList[VI_ERROR_RSRC_BUSY] = "The resource is valid, but VISA cannot currently access it.";
        ErrorList[VI_ERROR_RSRC_LOCKED] = "Specified type of lock cannot be obtained because the resource is already locked with a lock type incompatible with the lock requested.";
        ErrorList[VI_ERROR_TMO] = "A session to the resource could not be obtained within the specified openTimeout period.";
        ErrorList[VI_ERROR_LIBRARY_NFOUND] = "A code library required by VISA could not be located or loaded.";
        ErrorList[VI_ERROR_INTF_NUM_NCONFIG] = "The interface type is valid, but the specified interface number is not configured.";
        ErrorList[VI_ERROR_MACHINE_NAVAIL] = "The remote machine does not exist or is not accepting any connections. If the NI-VISA server is installed and running on the remote machine, it may have an incompatible version or may be listening on a different port.";
        ErrorList[VI_ERROR_NPERMISSION] = "Access to the remote machine is denied.";
        //viClose()
        ErrorList[VI_ERROR_INV_OBJECT] = "The given object reference is invalid.";
        ErrorList[VI_ERROR_CLOSING_FAILED] = "Unable to deallocate the previously allocated data structures corresponding to this session or object reference.";
        //viWrite
        ErrorList[VI_ERROR_INV_OBJECT] = "The given session reference is invalid.";
        ErrorList[VI_ERROR_NSUP_OPER] = "The given vi does not support this operation.";
        ErrorList[VI_ERROR_RSRC_LOCKED] = "Specified operation could not be performed because the resource identified by vi has been locked for this kind of access.";
        ErrorList[VI_ERROR_TMO] = "Timeout expired before operation completed.";
        ErrorList[VI_ERROR_RAW_WR_PROT_VIOL] = "Violation of raw write protocol occurred during transfer.";
        ErrorList[VI_ERROR_RAW_RD_PROT_VIOL] = "Violation of raw read protocol occurred during transfer.";
        ErrorList[VI_ERROR_INP_PROT_VIOL] = "Device reported an input protocol error during transfer.";
        ErrorList[VI_ERROR_BERR] = "Bus error occurred during transfer.";
        ErrorList[VI_ERROR_INV_SETUP] = "Unable to start write operation because setup is invalid (due to attributes being set to an inconsistent state).";
        ErrorList[VI_ERROR_NCIC] = "The interface associated with the given vi is not currently the controller in charge.";
        ErrorList[VI_ERROR_NLISTENERS] = "No-listeners condition is detected (both NRFD and NDAC are unasserted).";
        ErrorList[VI_ERROR_IO] = "An unknown I/O error occurred during transfer.";
        ErrorList[VI_ERROR_CONN_LOST] = "The I/O connection for the given session has been lost.";
        //viRead
        ErrorList[VI_ERROR_INV_OBJECT] = "The given session reference is invalid.";
        ErrorList[VI_ERROR_NSUP_OPER] = "The given vi does not support this operation.";
        ErrorList[VI_ERROR_RSRC_LOCKED] = "Specified operation could not be performed because the resource identified by vi has been locked for this kind of access.";
        ErrorList[VI_ERROR_TMO] = "Timeout expired before operation completed.";
        ErrorList[VI_ERROR_RAW_WR_PROT_VIOL] = "Violation of raw write protocol occurred during transfer.";
        ErrorList[VI_ERROR_RAW_RD_PROT_VIOL] = "Violation of raw read protocol occurred during transfer.";
        ErrorList[VI_ERROR_OUTP_PROT_VIOL] = "Device reported an output protocol error during transfer.";
        ErrorList[VI_ERROR_BERR] = "Bus error occurred during transfer.";
        ErrorList[VI_ERROR_INV_SETUP] = "Unable to start read operation because setup is invalid (due to attributes being set to an inconsistent state).";
        ErrorList[VI_ERROR_NCIC] = "The interface associated with the given vi is not currently the controller in charge.";
        ErrorList[VI_ERROR_NLISTENERS] = "No-listeners condition is detected (both NRFD and NDAC are unasserted).";
        ErrorList[VI_ERROR_ASRL_PARITY] = "A parity error occurred during transfer.";
        ErrorList[VI_ERROR_ASRL_FRAMING] = "A framing error occurred during transfer.";
        ErrorList[VI_ERROR_ASRL_OVERRUN] = "An overrun error occurred during transfer. A character was not read from the hardware before the next character arrived.";
        ErrorList[VI_ERROR_IO] = "An unknown I/O error occurred during transfer.";
        ErrorList[VI_ERROR_CONN_LOST] = "The I/O connection for the given session has been lost.";


    }
}

/*===========================================================================*/
BaseDevice::~BaseDevice(){
 //   delete outBuffer;
}
//USB0::0x0699::0x03A6::C011549::INSTR
/*===========================================================================*/
QString BaseDevice::ConnectDevice(QString typeConnect, QString typeAdder){
    QString outBuffer;
    QString adder = typeConnect + "::" + typeAdder + "::INSTR";
    status = viOpenDefaultRM(&rm);
    if (status < VI_SUCCESS)
        return( outBuffer = ErrorFunction(status));
    char* adr = new char [100];
    strcpy(adr, adder.toStdString().data());
    status = viOpen(rm, adr, VI_NULL, VI_NULL, &vi);
    delete[] adr;
    if (status < VI_SUCCESS)
        return(outBuffer = ErrorFunction(status));
    flag_connect = true;
    return ("");
}
/*===========================================================================*/
QString BaseDevice::DisconnectDevice(){
QString outBuffer;
   status = viClose(vi);
   if (status < VI_SUCCESS)
        return( outBuffer = ErrorFunction(status));
   status = viClose(rm);
   if (status < VI_SUCCESS)
        return( outBuffer = ErrorFunction(status));
        flag_connect = false;
   return("");
}
/*===========================================================================*/
QString BaseDevice::WriteCommand(QString command){

    if( flag_connect == false)
        return(" Не выполнена функция ConnectDevice");
    QString outBuffer;
    int size = command.size();
    char* cmd = new char [100];
    strcpy(cmd, command.toStdString().data());
    status = viWrite(vi, (ViBuf)cmd, size, &retCnt);
    delete[] cmd;
    if (status < VI_SUCCESS)
        return( outBuffer = ErrorFunction(status));
    return("");

}
/*===========================================================================*/
QString BaseDevice::ReadDevice( uint count){
    char* buffer = new char[count]{};
    if( flag_connect == false){
        delete[] buffer;
        return(" Не выполнена функция ConnectDevice");
    }
    QString outBuffer;
    status = viRead(vi, (ViBuf) buffer, count, &retCnt);
    if (status < VI_SUCCESS){
        delete[] buffer;
        return( outBuffer = ErrorFunction(status));
    }
    outBuffer = QString(QByteArray(buffer));
    delete[] buffer;
    return(outBuffer);
}
/*===========================================================================*/
QString BaseDevice::IDN(){

    WriteCommand("*idn?");
    return(ReadDevice(50));
}
/*===========================================================================*/
QString BaseDevice::RST(){
    return (WriteCommand("*rst"));
}
/*===========================================================================*/
QString BaseDevice::TST(){
    return (WriteCommand("*tst"));
}
/*===========================================================================*/
QString BaseDevice::WAI(){
    return (WriteCommand("*wai"));
}
/*===========================================================================*/
QString BaseDevice::ErrorFunction( ViStatus status){
    QString outbuffer;
    ViChar buffer[256]{};
    QMap<int,QString>::iterator it = ErrorList.begin();
    for( ; it != ErrorList.end(); it++){
        if(it.key() == status)
           outbuffer = it.value();
    }
    //ежели такой ошибкит нет, создаю строку с номером этой ошибки
    if(outbuffer.isNull()){
        viStatusDesc(vi, status, buffer);
       outbuffer = QString(QByteArray(buffer)); // QString(QByteArray(buffer, 255))
    }
    return outbuffer;
}




