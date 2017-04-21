#include <iostream>
#include <visa.h>
#include <visatype.h>
#include <memory.h>
//
#include <QApplication>
#include <ipdialog.h>
using namespace std;


    int main(int argc, char *argv[])
{
        //для регулярного выражения
    //    QApplication a(argc, argv);
   //     IpDialog ip;
   //     ip.show();
    cout << "Hello World!" << endl;
    ViSession	rm = VI_NULL, rm1 = VI_NULL,rm2 = VI_NULL,rm3 = VI_NULL,vi = VI_NULL;
    ViStatus	status;
    ViChar		buffer[256];
    ViUInt32	retCnt;



    // Open a d efault Session
    status = viOpenDefaultRM(&rm);
    if (status < VI_SUCCESS) goto error;


    // Open the gpib device at primary address 1, gpib board 8
  //  status = viOpen(rm, "TCPIP::192.168.1.26::INSTR", VI_NULL, VI_NULL, &vi);
    status = viOpen(rm, "TCPIP::192.168.70.39::INSTR", VI_NULL, VI_NULL, &vi);
    if (status < VI_SUCCESS) goto error;

    // Send an ID query.
    status = viWrite(vi, (ViBuf) "*idn?", 5, &retCnt);
    if (status < VI_SUCCESS) goto error;

    // Clear the buffer and read the response
    memset(buffer, 0, sizeof(buffer));
    status = viRead(vi, (ViBuf) buffer, sizeof(buffer), &retCnt);
    if (status < VI_SUCCESS) goto error;

    // Print the response
    printf("id: %s\n", buffer);

    // Clean up
    viClose(vi); // Not needed, but makes things a bit more understandable
    viClose(rm);

    return 0;
   //return a.exec();

error:
    // Report error and clean up
    viStatusDesc(vi, status, buffer);
    fprintf(stderr, "failure: %s\n", buffer);
    if (rm != VI_NULL) {
        viClose(rm);
    }
        return 1;

}


