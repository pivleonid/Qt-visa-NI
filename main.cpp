
//
//#include <QApplication>
//#include <ipdialog.h>
#include <basedevice.h>
#include <fsl.h>
#include <tds2024c.h>

using namespace std;


    int main(int argc, char *argv[])
{

        TDS2024C TDS;
        QString b;
        b = TDS.ConnectDevice("USB0", "0x0699::0x03A6::C011549");
        b = TDS.IDN();
        b = TDS.Trace_initial("1", "2500", "CH1", "ASCII");
        QList<QString> b1 = TDS.Trace();
        return 0;
        //для регулярного выражения
        //    QApplication a(argc, argv);
        //     IpDialog ip;
        //     ip.show();
        //return a.exec();

    }


