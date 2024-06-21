#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Cinema.h"
#include <QMainWindow>
#include <QApplication>
#include <QMainWindow>
#include <QAction>
#include <QFileDialog>
#include <QTextStream>
#include <QFile>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString file_directory = "";

private slots:
    void on_add_genre_clicked();

    void add_genre(QString genre);

    void on_remove_genre_clicked();

    void remove_genre(QString genre);

    void on_edit_genre_clicked();

    void add_secondgenre(QString genre, QString secondgenre);

    void on_add_movie_clicked();

    void add_movie(QString genre, QString movie, int price);

    void on_remove_movie_clicked();

    void remove_movie(QString movie);

    void on_edit_movie_clicked();

    void add_secondmovie(QString genre, QString movie, QString secondmovie, int newprice);

    void on_edit_price_clicked();

    void add_price(QString movie, int newprice);

    void on_find_genre_clicked();

    void find_genre(QString genre);

    void on_sorted_genre_clicked();

    void sort_genre(QString genre);

    void on_find_movie_clicked();

    void find_movie(QString movie);

    void on_display_clicked();

    void on_favorites_add_genre_clicked();

    void favorites_add_genre(QString genre);

    void on_favorites_remove_genre_clicked();

    void favorites_remove_genre(QString genre);

    void on_favorites_add_movie_clicked();

    void favorites_add_movie(QString genre, QString movie, int price);

    void on_favorites_remove_movie_clicked();

    void favorites_remove_movie(QString movie);

    void on_change_order_clicked();

    void change_order(QString genre, QString movie, QString secondgenre, QString secondmovie);

    void on_display_favorites_clicked();

    void on_pushButton_15_clicked();

    void on_exit_clicked();

    void on_actionSave_triggered();

    void on_actionLoad_triggered();

    void on_actionExport_triggered();

    void on_actionImport_triggered();

private:
    Ui::MainWindow *ui;
    Cinema cinema;
};
#endif // MAINWINDOW_H
