#include "genre.h"
#include "ui_genre.h"

Genre::Genre(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Genre)
{
    ui->setupUi(this);
}

Genre::~Genre()
{
    delete ui;
}

void Genre::on_buttonBox_accepted()
{
    for (auto a : ui->lineEdit->text())
    {
        if(!a.isLetterOrNumber())
        {
            QMessageBox::warning(this, "Error", "Invalid inputs!");
            return;
        }

    }

    emit genre_added(ui->lineEdit->text());
    emit genre_removed(ui->lineEdit->text());
    emit genre_found(ui->lineEdit->text());
    emit genre_sorted(ui->lineEdit->text());
    emit favorites_genre_added(ui->lineEdit->text());
    emit favorites_genre_removed(ui->lineEdit->text());
}
