#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QCoreApplication>
#include <QTextStream>
#include <QFile>
#include <QDebug>
#include <changeorder.h>
#include <genre.h>
#include <movie.h>
#include <nomovie.h>
#include <price.h>
#include <secondgenre.h>
#include <secondmovie.h>
#include <Cinema.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_add_genre_clicked()
{
    Genre *g = new Genre(this);
    connect(g, SIGNAL(genre_added(QString)), this, SLOT(add_genre(QString)));
    g->show();
}


void MainWindow::add_genre(QString genre)
{
    for (auto &kv : cinema.movies)
    {
        if (kv.first == "" + genre.toStdString())
        {
            QMessageBox::warning(this, "Error", "This genre already exists!");
            break;
        }

    }

    cinema.addGenre("" + genre.toStdString());
}


void MainWindow::on_remove_genre_clicked()
{
    Genre *g = new Genre(this);
    connect(g, SIGNAL(genre_removed(QString)), this, SLOT(remove_genre(QString)));
    g->show();
}


void MainWindow::remove_genre(QString genre)
{
    bool flag = false;

    for (auto &kv : cinema.movies)
    {
        if (kv.first == "" + genre.toStdString())
        {
            flag = true;
            break;
        }

    }

    if(!flag)
    {
        QMessageBox::warning(this, "Error", "This genre doesn't exist!");
    } else
    {
        cinema.removeGenre("" + genre.toStdString());
    }

}


void MainWindow::on_edit_genre_clicked()
{
    SecondGenre *sg = new SecondGenre(this);
    connect(sg, SIGNAL(secondgenre_added(QString,QString)), this, SLOT(add_secondgenre(QString,QString)));
    sg->show();
}


void MainWindow::add_secondgenre(QString genre, QString secondgenre)
{
    bool flag = false;

    for (auto &kv : cinema.movies)
    {
        if (kv.first == "" + genre.toStdString())
        {
            flag = true;
            break;
        }

    }

    if(!flag)
    {
        QMessageBox::warning(this, "Error", "This genre doesn't exist!");
    } else
    {
        cinema.editGenre("" + genre.toStdString(), "" + secondgenre.toStdString());
    }

}


void MainWindow::on_add_movie_clicked()
{
    Movie *m = new Movie(this);
    connect(m, SIGNAL(movie_added(QString,QString,int)), this, SLOT(add_movie(QString,QString,int)));
    m->show();
}


void MainWindow::add_movie(QString genre, QString movie, int price)
{
    for (auto &kv : cinema.movies)
    {
        if (kv.second.first == "" + movie.toStdString() && kv.first == "" + genre.toStdString())
        {
            QMessageBox::warning(this, "Error", "This movie already exists!");
            break;
        }

    }

    if(movie == "")
    {
        QMessageBox::warning(this, "Error", "This movie isn't allowed!");
    }else
    {
        cinema.addMovie("" + genre.toStdString(), "" + movie.toStdString(), price);
    }

}


void MainWindow::on_remove_movie_clicked()
{
    NoMovie *nm = new NoMovie(this);
    connect(nm, SIGNAL(movie_removed(QString)), this, SLOT(remove_movie(QString)));
    nm->show();
}


void MainWindow::remove_movie(QString movie)
{
    bool flag = false;

    for (auto &kv : cinema.movies)
    {
        if (kv.second.first == "" + movie.toStdString())
        {
            flag = true;
            break;
        }

    }

    if(movie == "")
    {
        QMessageBox::warning(this, "Error", "This movie isn't allowed!");
    }else if(!flag)
    {
        QMessageBox::warning(this, "Error", "This movie doesn't exist!");
    } else
    {
        cinema.removeMovie("" + movie.toStdString());
    }

}


void MainWindow::on_edit_movie_clicked()
{
    SecondMovie *sm = new SecondMovie(this);
    connect(sm, SIGNAL(secondmovie_added(QString,QString,QString,int)), this, SLOT(add_secondmovie(QString,QString,QString,int)));
    sm->show();
}


void MainWindow::add_secondmovie(QString genre, QString movie, QString secondmovie, int price)
{
    bool flag = false;

    for (auto &kv : cinema.movies)
    {
        if (kv.second.first == "" + movie.toStdString() && kv.first == "" + genre.toStdString())
        {
            flag = true;
            break;
        }

    }
    if(secondmovie == "")
    {
        QMessageBox::warning(this, "Error", "This movie isn't allowed!");
    }else if(!flag)
    {
        QMessageBox::warning(this, "Error", "This movie doesn't exist!");
    } else
    {
        cinema.editMovie("" + genre.toStdString(), "" + movie.toStdString(), "" + secondmovie.toStdString(), price);
    }

}


void MainWindow::on_edit_price_clicked()
{
    Price *p = new Price(this);
    connect(p, SIGNAL(price_added(QString,int)), this, SLOT(add_price(QString,int)));
    p->show();
}


void MainWindow::add_price(QString movie, int newprice)
{
    bool flag = false;

    for (auto &kv : cinema.movies)
    {
        if (kv.second.first == "" + movie.toStdString())
        {
            flag = true;
            break;
        }

    }

    if(!flag)
    {
        QMessageBox::warning(this, "Error", "This movie doesn't exist!");
    } else
    {
        cinema.editPrice( "" + movie.toStdString(), newprice);
    }
}


void MainWindow::on_find_genre_clicked()
{
    Genre *g = new Genre(this);
    connect(g, SIGNAL(genre_found(QString)), this, SLOT(find_genre(QString)));
    g->show();
}


void MainWindow::find_genre(QString genre)
{
    bool flag = false;

    for (auto &kv : cinema.movies)
    {
        if (kv.first == "" + genre.toStdString())
        {
            flag = true;
            break;
        }

    }

    if(!flag)
    {
        QMessageBox::warning(this, "Error", "This genre doesn't exist!");
    } else
    {
        ui->textEdit->clear();
        QString current_key = "";

        for (const auto& kv : cinema.movies)
        {
            string s;

            if (kv.first == ("" + genre.toStdString()))
            {
                if (kv.first != ("" + current_key.toStdString()))
                {
                    if (kv.second.first == "")
                    {
                        s += kv.first + ": \n\t (empty)";
                        ui->textEdit->append(QString::fromStdString(s));
                        continue;
                    }

                    current_key = QString::fromStdString(kv.first);
                    s += kv.first + ": \n\t" + kv.second.first + ": " + to_string(kv.second.second);
                } else
                {
                    s += "\t" + kv.second.first + ": " + to_string(kv.second.second);
                }

            }

            ui->textEdit->append(QString::fromStdString(s));

        }

        ui->textEdit->append("");

    }

}


void MainWindow::on_sorted_genre_clicked()
{
    Genre *g = new Genre(this);
    connect(g, SIGNAL(genre_sorted(QString)), this, SLOT(sort_genre(QString)));
    g->show();
}


void MainWindow::sort_genre(QString genre)
{
    bool flag = false;

    for (auto &kv : cinema.movies)
    {
        if (kv.first == "" + genre.toStdString())
        {
            flag = true;
            break;
        }

    }

    if(!flag)
    {
        QMessageBox::warning(this, "Error", "This genre doesn't exist!");
    } else
    {
        ui->textEdit->clear();
        QString current_key = "";
        map<int, string> films;

        for (const auto& kv : cinema.movies)
        {
            if (kv.first == ("" + genre.toStdString()))
            {
                films.insert(make_pair(kv.second.second, kv.second.first));
            }

        }

        string s;
        s += "" + genre.toStdString() + ":";
        ui->textEdit->append(QString::fromStdString(s));

        for (auto &kv : films)
        {
            s = "";

            if (kv.second != ("" + current_key.toStdString()))
            {
                if (kv.second == "")
                {
                    s += "\t(empty)";
                    ui->textEdit->append(QString::fromStdString(s));
                    continue;
                }

                current_key = QString::number(kv.first);
                s += "\t" + kv.second + ": " + to_string(kv.first);
            } else
            {
                s += "\t" + kv.second + ": " + to_string(kv.first);
            }

            ui->textEdit->append(QString::fromStdString(s));

        }

        ui->textEdit->append("");

    }

}


void MainWindow::on_find_movie_clicked()
{
    NoMovie *nm = new NoMovie(this);
    connect(nm, SIGNAL(movie_found(QString)), this, SLOT(find_movie(QString)));
    nm->show();
}


void MainWindow::find_movie(QString movie)
{
    bool flag = false;

    for (auto &kv : cinema.movies)
    {
        if (kv.second.first == "" + movie.toStdString())
        {
            flag = true;
            break;
        }

    }

    if(!flag)
    {
        QMessageBox::warning(this, "Error", "This movie doesn't exist!");
    } else
    {
        ui->textEdit->clear();
        QString current_key = "";

        string s;
        s +=  "" + movie.toStdString() + ": ";
        ui->textEdit->append(QString::fromStdString(s));

        for (const auto& kv : cinema.movies)
        {
            s = "";

            if (kv.second.first == ("" + movie.toStdString()))
            {
                if (kv.first != ("" + current_key.toStdString()))
                {
                    current_key = QString::fromStdString(kv.first);
                    s += "\t" + kv.first + ": " + to_string(kv.second.second);
                } else
                {
                    s += "\t" + kv.first + ": " + to_string(kv.second.second);
                }

            }

            ui->textEdit->append(QString::fromStdString(s));

        }

        ui->textEdit->append("");

    }

}


void MainWindow::on_display_clicked()
{
    ui->textEdit->clear();
    QString current_key = "";

    for (const auto& kv : cinema.movies)
    {
        string s = "";

        if (kv.first != ("" + current_key.toStdString()))
        {
            if (kv.second.first == "")
            {
                s += kv.first + ":\n\t(empty)";
                ui->textEdit->append(QString::fromStdString(s));
                continue;
            }

            current_key = QString::fromStdString(kv.first);
            s += kv.first + ":\n\t" + kv.second.first + ": " + to_string(kv.second.second);
        } else
        {
            s += "\t" + kv.second.first + ": " + to_string(kv.second.second);
        }

        ui->textEdit->append(QString::fromStdString(s));
    }

    ui->textEdit->append("");
}


void MainWindow::on_favorites_add_genre_clicked()
{
    Genre *g = new Genre(this);
    connect(g, SIGNAL(favorites_genre_added(QString)), this, SLOT(favorites_add_genre(QString)));
    g->show();
}


void MainWindow::favorites_add_genre(QString genre)
{
    for (auto &kv : cinema.favorites)
    {
        if (kv.first == "" + genre.toStdString())
        {
            QMessageBox::warning(this, "Error", "This genre already exists!");
            break;
        }

    }

   cinema.favoritesAddGenre("" + genre.toStdString());
}


void MainWindow::on_favorites_remove_genre_clicked()
{
    Genre *g = new Genre(this);
    connect(g, SIGNAL(favorites_genre_removed(QString)), this, SLOT(favorites_remove_genre(QString)));
    g->show();
}


void MainWindow::favorites_remove_genre(QString genre)
{
    bool flag = false;

    for (auto &kv : cinema.favorites)
    {
        if (kv.first == "" + genre.toStdString())
        {
            flag = true;
            break;
        }

    }

    if(!flag)
    {
        QMessageBox::warning(this, "Error", "This genre doesn't exist!");
    } else
    {
        cinema.favoritesRemoveGenre("" + genre.toStdString());
    }

}


void MainWindow::on_favorites_add_movie_clicked()
{
    Movie *m = new Movie(this);
    connect(m, SIGNAL(favorites_movie_added(QString,QString,int)), this, SLOT(favorites_add_movie(QString,QString,int)));
    m->show();
}


void MainWindow::favorites_add_movie(QString genre, QString movie, int price)
{
    for (auto &kv : cinema.favorites)
    {
        if (kv.second.first == "" + movie.toStdString() && kv.first == "" + genre.toStdString())
        {
            QMessageBox::warning(this, "Error", "This movie already exists!");
            break;
        }

    }

    if(movie == "")
    {
        QMessageBox::warning(this, "Error", "This movie isn't allowed!");
    }else
    {
        cinema.favoritesAddMovie("" + genre.toStdString(), "" + movie.toStdString(), price);
    }

}


void MainWindow::on_favorites_remove_movie_clicked()
{
    NoMovie *nm = new NoMovie(this);
    connect(nm, SIGNAL(favorites_movie_removed(QString)), this, SLOT(favorites_remove_movie(QString)));
    nm->show();
}


void MainWindow::favorites_remove_movie(QString movie)
{
    bool flag = false;

    for (auto &kv : cinema.favorites)
    {
        if (kv.second.first == "" + movie.toStdString())
        {
            flag = true;
            break;
        }

    }

    if(movie == "")
    {
        QMessageBox::warning(this, "Error", "This movie isn't allowed!");
    }else if(!flag)
    {
        QMessageBox::warning(this, "Error", "This movie doesn't exist!");
    } else
    {
        cinema.favoritesRemoveMovie("" + movie.toStdString());
    }

}


void MainWindow::on_change_order_clicked()
{
    ChangeOrder *c = new ChangeOrder(this);
    connect(c, SIGNAL(order_changed(QString,QString,QString,QString)), this, SLOT(change_order(QString,QString,QString,QString)));
    c->show();
}


void MainWindow::change_order(QString genre, QString movie, QString secondgenre, QString secondmovie)
{
    auto it1 = find_if(cinema.favorites.begin(), cinema.favorites.end(), [genre](auto x){return x.first == "" + genre.toStdString();});
    auto it2 = find_if(cinema.favorites.begin(), cinema.favorites.end(), [secondgenre](auto x){return x.first == "" + secondgenre.toStdString();});
    bool flag = false;

    if (it1 == cinema.favorites.end() || it1->second.first == "")
    {
        QMessageBox::warning(this, "Error", "The first movie doesn't exist!");
        flag = true;
    }

    if (it2 == cinema.favorites.end() || it2->second.first == "")
    {
        QMessageBox::warning(this, "Error", "The second movie doesn't exist!");
        flag = true;
    }

    if (!flag)
    {
        cinema.changeOrder("" + genre.toStdString(), "" + movie.toStdString(), "" + secondgenre.toStdString(), "" + secondmovie.toStdString());
    }

}


void MainWindow::on_display_favorites_clicked()
{
    ui->textEdit->clear();

    for (auto &elem : cinema.favorites)
    {

        if (elem.second.first == "")
        {
            ui->textEdit->append("genre: "  + QString::fromStdString(elem.first) + "(empty)");
        } else
        {
            ui->textEdit->append("genre: "  + QString::fromStdString(elem.first) + ", movie: " + QString::fromStdString(elem.second.first) + ", price: " + QString::number(elem.second.second));
        }

    }

}


void MainWindow::on_pushButton_15_clicked()
{

}


void MainWindow::on_exit_clicked()
{
    QApplication::quit();
}

void MainWindow::on_actionSave_triggered()
{
    QString filePath = "";

    if(file_directory == "")
    {
        filePath += "" + QFileDialog::getSaveFileName(this, "Save File", "", "Text Files (*.txt);;All Files (*)");
        file_directory = filePath;

        if (filePath.isEmpty())
        {
            return;
        }

    }

    QFile file(file_directory);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, tr("Error"), tr("Unable to open file for writing."));
        return;
    }
    ui->textEdit->clear();
    QString tmp = ui->textEdit->toPlainText();
    on_display_clicked();
    file.write("**********\n" + ui->textEdit->toPlainText().toUtf8() + "----------");

    file.close();

    ui->textEdit->append(tmp);
}


void MainWindow::on_actionLoad_triggered()
{
    QString filePath = "";

    if(file_directory == "")
    {
        filePath += "" + QFileDialog::getOpenFileName(this, "Open File", "", "Text Files (*.txt);;All Files (*)");
        file_directory = filePath;

        if (filePath.isEmpty())
        {
            return;
        }

    }

    QFile file(file_directory);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, tr("Error"), tr("Unable to open file for reading."));
        return;
    }

    QString tmp = ui->textEdit->toPlainText();
    ui->textEdit->clear();
    ui->textEdit->setPlainText(file.readAll());
    QString s = ui->textEdit->toPlainText();

    int i = 10;

    while (i < s.length() && s[i + 1] != '-')
    {
        QString genre = "";
        QString movie = "";
        int price = 0;
        bool flag = true;

        if( s[i] == '\n' && s[i + 1] != '\t')
        {
            int j = i;

            for(;j < s.length() - 1 && s[j + 1] != ':'; j++)
            {
                if(!s[j + 1].isLetterOrNumber())
                {
                    QMessageBox::warning(this, tr("Error"), tr("Unable to read the file."));
                    return;
                }

                genre += s[j + 1];
            }

            i = j + 2;
        }

        if (s[i] == '\n' && s[i + 1] == '\t' && s[i + 2] != '(')
        {
            int j = i;

            while(j < s.length() - 2 && s[j + 2] != ':')
            {
                if(!s[j + 2].isLetterOrNumber())
                {
                    QMessageBox::warning(this, tr("Error"), tr("Unable to read the file."));
                    return;
                }

                movie += s[j + 2];
                j++;
            }

            j += 3;

            while (j < s.length() - 1 && s[j + 1] != '\n')
            {
                if(!s[j + 1].isDigit())
                {
                    QMessageBox::warning(this, tr("Error"), tr("Unable to read the file."));
                    return;
                }

                price = price * 10 + s[j + 1].digitValue();
                j++;
            }

            i = j;
        } else if (s[i] == '\n' && s[i + 1] == '\t' && s[i + 2] == '(')
        {
            flag = false;
            i += 8;
        }

        if(movie == "" && flag)
        {
            QMessageBox::warning(this, tr("Error"), tr("Unable to read the file."));
            return;
        }else
        {
            cinema.addMovie("" + genre.toStdString(), "" + movie.toStdString(), price);
        }

        i++;
    }

    file.close();

    ui->textEdit->clear();
    ui->textEdit->append(tmp);
}


void MainWindow::on_actionExport_triggered()
{
    QString filePath = "" + QFileDialog::getSaveFileName(this, "Save File", "", "Text Files (*.txt);;All Files (*)");
    file_directory = filePath;

    if (filePath.isEmpty())
    {
        return;
    }

    QFile file(file_directory);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, tr("Error"), tr("Unable to open file for writing."));
        return;
    }

    QString tmp = ui->textEdit->toPlainText();
    on_display_clicked();
    file.write("**********\n" + ui->textEdit->toPlainText().toUtf8());
    on_display_favorites_clicked();
    file.write("----------\n" + ui->textEdit->toPlainText().toUtf8());

    file.close();

    ui->textEdit->clear();
    ui->textEdit->append(tmp);
}


void MainWindow::on_actionImport_triggered()
{
    QString filePath = "" + QFileDialog::getOpenFileName(this, "Open File", "", "Text Files (*.txt);;All Files (*)");
    file_directory = filePath;


    QFile file(file_directory);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, tr("Error"), tr("Unable to open file for reading."));
        return;
    }

    QString tmp = ui->textEdit->toPlainText();
    ui->textEdit->clear();
    ui->textEdit->setPlainText(file.readAll());
    QString s = ui->textEdit->toPlainText();

    int i = 10;

    while (i < s.length() && s[i + 1] != '-')
    {
        QString genre = "";
        QString movie = "";
        int price = 0;
        bool flag = true;

        if( s[i] == '\n' && s[i + 1] != '\t')
        {
            int j = i;

            for(;j < s.length() - 1 && s[j + 1] != ':'; j++)
            {
                if(!s[j + 1].isLetterOrNumber())
                {
                    QMessageBox::warning(this, tr("Error"), tr("Unable to read the file."));
                    return;
                }

                genre += s[j + 1];
            }

            i = j + 2;
        }

        if (s[i] == '\n' && s[i + 1] == '\t' && s[i + 2] != '(')
        {
            int j = i;

            while(j < s.length() - 2 && s[j + 2] != ':')
            {
                if(!s[j + 2].isLetterOrNumber())
                {
                    QMessageBox::warning(this, tr("Error"), tr("Unable to read the file."));
                    return;
                }

                movie += s[j + 2];
                j++;
            }

            j += 3;

            while (j < s.length() - 1 && s[j + 1] != '\n')
            {
                if(!s[j + 1].isDigit())
                {
                    QMessageBox::warning(this, tr("Error"), tr("Unable to read the file."));
                    return;
                }

                price = price * 10 + s[j + 1].digitValue();
                j++;
            }

            i = j;
        } else if (s[i] == '\n' && s[i + 1] == '\t' && s[i + 2] == '(')
        {
            flag = false;
            i += 8;
        }

        if(movie == "" && flag)
        {
            QMessageBox::warning(this, tr("Error"), tr("Unable to read the file."));
            return;
        }else
        {
            cinema.addMovie("" + genre.toStdString(), "" + movie.toStdString(), price);
        }

        i++;
    }

    file.close();

    ui->textEdit->clear();
    ui->textEdit->append(tmp);
}

