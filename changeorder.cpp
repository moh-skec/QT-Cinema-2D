#include "changeorder.h"
#include "ui_changeorder.h"

ChangeOrder::ChangeOrder(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChangeOrder)
{
    ui->setupUi(this);
}

ChangeOrder::~ChangeOrder()
{
    delete ui;
}

void ChangeOrder::on_buttonBox_accepted()
{    for (auto a : ui->lineEdit->text())
    {
        if(!a.isLetterOrNumber())
        {
            QMessageBox::warning(this, "Error", "Invalid inputs!");
            return;
        }

    }

    for (auto a : ui->lineEdit_2->text())
    {
        if(!a.isLetterOrNumber())
        {
            QMessageBox::warning(this, "Error", "Invalid inputs!");
            return;
        }

    }

    for (auto a : ui->lineEdit_3->text())
    {
        if(!a.isLetterOrNumber())
        {
            QMessageBox::warning(this, "Error", "Invalid inputs!");
            return;
        }

    }

    for (auto a : ui->lineEdit_4->text())
    {
        if(!a.isLetterOrNumber())
        {
            QMessageBox::warning(this, "Error", "Invalid inputs!");
            return;
        }

    }

    emit order_changed(ui->lineEdit->text(), ui->lineEdit_2->text(), ui->lineEdit_3->text(), ui->lineEdit_4->text());
}

