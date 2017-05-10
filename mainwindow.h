#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include <basedevice.h>
#include <fsl.h>
#include <tds2024c.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    FSL* FSL_Device;
    TDS2024C* TDS_Device;
    enum stateDevice{off, tds, fsl};
    stateDevice mainStateDevice = off;
private slots:
    void connect_button();
    void discon_button();
    void clear_log();
    void InitializeDevice(QString Divice);
    void Replot_Image();
    void ResetDevice();
    void TraceButton();
};

#endif // MAINWINDOW_H
