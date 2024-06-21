#ifndef SECONDGENRE_H
#define SECONDGENRE_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class SecondGenre;
}

class SecondGenre : public QDialog
{
    Q_OBJECT

public:
    explicit SecondGenre(QWidget *parent = nullptr);
    ~SecondGenre();

private slots:
    void on_buttonBox_accepted();

signals:
    void secondgenre_added(QString, QString);

private:
    Ui::SecondGenre *ui;
};

#endif // SECONDGENRE_H
