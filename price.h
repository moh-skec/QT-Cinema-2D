#ifndef PRICE_H
#define PRICE_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class Price;
}

class Price : public QDialog
{
    Q_OBJECT

public:
    explicit Price(QWidget *parent = nullptr);
    ~Price();

private slots:
    void on_buttonBox_accepted();

signals:
    void price_added(QString, int);

private:
    Ui::Price *ui;
};

#endif // PRICE_H
