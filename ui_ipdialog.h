/********************************************************************************
** Form generated from reading UI file 'ipdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IPDIALOG_H
#define UI_IPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_IpDialog
{
public:
    QPushButton *pushButton;
    QLineEdit *lineEdit;

    void setupUi(QDialog *IpDialog)
    {
        if (IpDialog->objectName().isEmpty())
            IpDialog->setObjectName(QStringLiteral("IpDialog"));
        IpDialog->resize(365, 54);
        pushButton = new QPushButton(IpDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(270, 10, 93, 28));
        lineEdit = new QLineEdit(IpDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 10, 241, 31));

        retranslateUi(IpDialog);

        QMetaObject::connectSlotsByName(IpDialog);
    } // setupUi

    void retranslateUi(QDialog *IpDialog)
    {
        IpDialog->setWindowTitle(QApplication::translate("IpDialog", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("IpDialog", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class IpDialog: public Ui_IpDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IPDIALOG_H
