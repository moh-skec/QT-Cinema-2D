#include "price.h"
#include "ui_price.h"

Price::Price(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Price)
{
    ui->setupUi(this);
}

Price::~Price()
{
    delete ui;
}

void Price::on_buttonBox_accepted()
{
    for (auto a : ui->lineEdit->text())
    {
        if(!a.isLetterOrNumber())
        {
            QMessageBox::warning(this, "Error", "Invalid inputs!");
            return;
        }

    }

    for (auto a : ui->lineEdit_2->text())
    {
        if(!a.isNumber())
        {
            QMessageBox::warning(this, "Error", "Invalid inputs!");
            return;
        }

    }

    emit price_added(ui->lineEdit->text(),ui->lineEdit_2->text().toInt());
}

