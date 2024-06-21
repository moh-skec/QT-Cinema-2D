#include "secondmovie.h"
#include "ui_secondmovie.h"

SecondMovie::SecondMovie(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SecondMovie)
{
    ui->setupUi(this);
}

SecondMovie::~SecondMovie()
{
    delete ui;
}

void SecondMovie::on_buttonBox_accepted()
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
        if(!a.isNumber())
        {
            QMessageBox::warning(this, "Error", "Invalid inputs!");
            return;
        }

    }

    emit secondmovie_added(ui->lineEdit->text(), ui->lineEdit_2->text(), ui->lineEdit_3->text(), ui->lineEdit_4->text().toInt());
}

