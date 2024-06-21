#ifndef CHANGEORDER_H
#define CHANGEORDER_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class ChangeOrder;
}

class ChangeOrder : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeOrder(QWidget *parent = nullptr);
    ~ChangeOrder();

private slots:
    void on_buttonBox_accepted();

signals:
    void order_changed(QString, QString, QString, QString);

private:
    Ui::ChangeOrder *ui;
};

#endif // CHANGEORDER_H
