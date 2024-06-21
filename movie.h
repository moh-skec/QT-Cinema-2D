#ifndef MOVIE_H
#define MOVIE_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class Movie;
}

class Movie : public QDialog
{
    Q_OBJECT

public:
    explicit Movie(QWidget *parent = nullptr);
    ~Movie();

private slots:
    void on_buttonBox_accepted();

signals:
    void movie_added(QString, QString, int);

    void favorites_movie_added(QString, QString, int);

private:
    Ui::Movie *ui;
};

#endif // MOVIE_H
