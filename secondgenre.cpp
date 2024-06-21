#include "secondgenre.h"
#include "ui_secondgenre.h"

SecondGenre::SecondGenre(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SecondGenre)
{
    ui->setupUi(this);
}

SecondGenre::~SecondGenre()
{
    delete ui;
}

void SecondGenre::on_buttonBox_accepted()
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

    emit secondgenre_added(ui->lineEdit->text(), ui->lineEdit_2->text());
}

