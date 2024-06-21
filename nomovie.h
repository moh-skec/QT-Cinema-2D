#ifndef NOMOVIE_H
#define NOMOVIE_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class NoMovie;
}

class NoMovie : public QDialog
{
    Q_OBJECT

public:
    explicit NoMovie(QWidget *parent = nullptr);
    ~NoMovie();

private slots:
    void on_buttonBox_accepted();

signals:
    void movie_removed(QString);

    void movie_found(QString);

    void favorites_movie_removed(QString);

private:
    Ui::NoMovie *ui;
};

#endif // NOMOVIE_H
