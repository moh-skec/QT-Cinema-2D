#include "nomovie.h"
#include "ui_nomovie.h"

NoMovie::NoMovie(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NoMovie)
{
    ui->setupUi(this);
}

NoMovie::~NoMovie()
{
    delete ui;
}

void NoMovie::on_buttonBox_accepted()
{
    for (auto a : ui->lineEdit->text())
    {
        if(!a.isLetterOrNumber())
        {
            QMessageBox::warning(this, "Error", "Invalid inputs!");
            return;
        }

    }

    emit movie_removed(ui->lineEdit->text());
    emit movie_found(ui->lineEdit->text());
    emit favorites_movie_removed(ui->lineEdit->text());
}

