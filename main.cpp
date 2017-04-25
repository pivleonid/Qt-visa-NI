
//
//#include <QApplication>
//#include <ipdialog.h>
#include <basedevice.h>

using namespace std;


    int main(int argc, char *argv[])
{
        BaseDevice someDevice;
        QString a;

        a = someDevice.ConnectDevice("TCPIP", "192.168.70.39");
        a =  someDevice.IDN();
        a =  someDevice.RST();
        a =  someDevice.TST();
        a =  someDevice.WAI();


        return 0;
        //для регулярного выражения
        //    QApplication a(argc, argv);
        //     IpDialog ip;
        //     ip.show();
        //return a.exec();

    }


