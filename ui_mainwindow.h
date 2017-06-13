/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
//#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_7;
//    QCustomPlot *widget;
    QGridLayout *gridLayout_6;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QComboBox *DeviceBox_2;
    QComboBox *DeviceBox;
    QSpacerItem *horizontalSpacer;
    QComboBox *BoxChannel;
    QLineEdit *adderLine;
    QGridLayout *gridLayout_4;
    QPushButton *connectButton;
    QPushButton *RST;
    QPushButton *DisconnectButton;
    QGraphicsView *graphicsView;
    QGridLayout *gridLayout_5;
    QListWidget *LogList;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout_3;
    QPushButton *buttonTrace;
    QLabel *labelTDS;
    QLabel *labelFSL;
    QPushButton *ButtonBufferClear;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1003, 821);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_7 = new QGridLayout(centralwidget);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        widget = new QCustomPlot(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(981, 521));

        gridLayout_7->addWidget(widget, 0, 0, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);


        horizontalLayout->addLayout(verticalLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        DeviceBox_2 = new QComboBox(centralwidget);
        DeviceBox_2->setObjectName(QStringLiteral("DeviceBox_2"));

        gridLayout->addWidget(DeviceBox_2, 0, 0, 1, 1);

        DeviceBox = new QComboBox(centralwidget);
        DeviceBox->setObjectName(QStringLiteral("DeviceBox"));

        gridLayout->addWidget(DeviceBox, 0, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        BoxChannel = new QComboBox(centralwidget);
        BoxChannel->setObjectName(QStringLiteral("BoxChannel"));

        gridLayout->addWidget(BoxChannel, 0, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        adderLine = new QLineEdit(centralwidget);
        adderLine->setObjectName(QStringLiteral("adderLine"));
        adderLine->setMaximumSize(QSize(16777215, 30));

        gridLayout_2->addWidget(adderLine, 1, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        connectButton = new QPushButton(centralwidget);
        connectButton->setObjectName(QStringLiteral("connectButton"));
        connectButton->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(connectButton->sizePolicy().hasHeightForWidth());
        connectButton->setSizePolicy(sizePolicy1);
        connectButton->setAutoFillBackground(false);
        connectButton->setCheckable(false);
        connectButton->setAutoDefault(false);
        connectButton->setFlat(false);

        gridLayout_4->addWidget(connectButton, 0, 0, 1, 1);

        RST = new QPushButton(centralwidget);
        RST->setObjectName(QStringLiteral("RST"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(RST->sizePolicy().hasHeightForWidth());
        RST->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(RST, 0, 2, 2, 1);

        DisconnectButton = new QPushButton(centralwidget);
        DisconnectButton->setObjectName(QStringLiteral("DisconnectButton"));
        DisconnectButton->setEnabled(true);
        sizePolicy1.setHeightForWidth(DisconnectButton->sizePolicy().hasHeightForWidth());
        DisconnectButton->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(DisconnectButton, 1, 0, 1, 1);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        gridLayout_4->addWidget(graphicsView, 0, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout_4);


        gridLayout_6->addLayout(horizontalLayout, 0, 0, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        LogList = new QListWidget(centralwidget);
        LogList->setObjectName(QStringLiteral("LogList"));
        LogList->setMaximumSize(QSize(16777215, 200));

        gridLayout_5->addWidget(LogList, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        buttonTrace = new QPushButton(centralwidget);
        buttonTrace->setObjectName(QStringLiteral("buttonTrace"));

        gridLayout_3->addWidget(buttonTrace, 0, 0, 1, 1);

        labelTDS = new QLabel(centralwidget);
        labelTDS->setObjectName(QStringLiteral("labelTDS"));
        labelTDS->setInputMethodHints(Qt::ImhExclusiveInputMask);
        labelTDS->setFrameShape(QFrame::WinPanel);
        labelTDS->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(labelTDS, 1, 0, 1, 1);

        labelFSL = new QLabel(centralwidget);
        labelFSL->setObjectName(QStringLiteral("labelFSL"));
        labelFSL->setFrameShape(QFrame::WinPanel);
        labelFSL->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(labelFSL, 2, 0, 1, 1);

        ButtonBufferClear = new QPushButton(centralwidget);
        ButtonBufferClear->setObjectName(QStringLiteral("ButtonBufferClear"));

        gridLayout_3->addWidget(ButtonBufferClear, 3, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        gridLayout_5->addLayout(verticalLayout_2, 0, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 1, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_6, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1003, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        connectButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\320\242\320\270\320\277 \321\201\320\276\320\265\320\264\320\270\320\275\320\265\320\275\320\270\321\217:", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\320\220\320\264\321\200\320\265\321\201 \320\277\321\200\320\270\320\261\320\276\321\200\320\260:", Q_NULLPTR));
        DeviceBox_2->clear();
        DeviceBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "USB", Q_NULLPTR)
         << QApplication::translate("MainWindow", "TCPIP", Q_NULLPTR)
         << QApplication::translate("MainWindow", "GPIB", Q_NULLPTR)
        );
        DeviceBox->clear();
        DeviceBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "TDS2024C", Q_NULLPTR)
         << QApplication::translate("MainWindow", "FSL", Q_NULLPTR)
        );
        BoxChannel->clear();
        BoxChannel->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "CH1", Q_NULLPTR)
         << QApplication::translate("MainWindow", "CH2", Q_NULLPTR)
         << QApplication::translate("MainWindow", "CH3", Q_NULLPTR)
         << QApplication::translate("MainWindow", "CH4", Q_NULLPTR)
         << QApplication::translate("MainWindow", "MATH", Q_NULLPTR)
         << QApplication::translate("MainWindow", "FFT", Q_NULLPTR)
        );
        adderLine->setText(QApplication::translate("MainWindow", "USB0::0x0699::0x03A6::C011549::INSTR", Q_NULLPTR));
        connectButton->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
        RST->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\267\320\260\320\263\321\200\321\203\320\267\320\272\320\260", Q_NULLPTR));
        DisconnectButton->setText(QApplication::translate("MainWindow", "Disconnect", Q_NULLPTR));
        buttonTrace->setText(QApplication::translate("MainWindow", "\320\241\320\275\321\217\321\202\321\214 \n"
"\320\242\321\200\320\265\320\271\321\201", Q_NULLPTR));
        labelTDS->setText(QApplication::translate("MainWindow", "TDS2024C", Q_NULLPTR));
        labelFSL->setText(QApplication::translate("MainWindow", "FSL", Q_NULLPTR));
        ButtonBufferClear->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\272\320\260 \320\273\320\276\320\263\320\276\320\262", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
