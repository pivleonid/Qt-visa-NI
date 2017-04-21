#include "ipdialog.h"
#include "ui_ipdialog.h"

IpDialog::IpDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IpDialog)
{
    ui->setupUi(this);
        /* Создаем строку для регулярного выражения */
    QString ipRange = "(?:[0-1]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])";
    /* Создаем регулярное выражение с применением строки, как
     * повторяющегося элемента
     */
    QRegExp ipRegex ("^" + ipRange
                     + "\\." + ipRange
                     + "\\." + ipRange
                     + "\\." + ipRange + "$");
    /* Создаем Валидатор регулярного выражения с применением
     * созданного регулярного выражения
     */
    QRegExpValidator *ipValidator = new QRegExpValidator(ipRegex, this);
    /* Устанавливаем Валидатор на QLineEdit */
    ui->lineEdit->setValidator(ipValidator);
}

IpDialog::~IpDialog()
{
    delete ui;
}
