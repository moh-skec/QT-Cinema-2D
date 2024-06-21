#ifndef GENRE_H
#define GENRE_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class Genre;
}

class Genre : public QDialog
{
    Q_OBJECT

public:
    explicit Genre(QWidget *parent = nullptr);
    ~Genre();

private slots:
    void on_buttonBox_accepted();

signals:
    void genre_added(QString);

    void genre_removed(QString);

    void genre_found(QString);

    void genre_sorted(QString);

    void favorites_genre_added(QString);

    void favorites_genre_removed(QString);

private:
    Ui::Genre *ui;
};

#endif // GENRE_H
