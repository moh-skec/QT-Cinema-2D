#ifndef SECONDMOVIE_H
#define SECONDMOVIE_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class SecondMovie;
}

class SecondMovie : public QDialog
{
    Q_OBJECT

public:
    explicit SecondMovie(QWidget *parent = nullptr);
    ~SecondMovie();

signals:
    void secondmovie_added(QString, QString, QString, int);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::SecondMovie *ui;
};

#endif // SECONDMOVIE_H
