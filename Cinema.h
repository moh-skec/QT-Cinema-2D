#ifndef CINEMA
#define CINEMA

#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Cinema
{
public:
    multimap<string, pair<string, int>> movies;
    vector<pair<string, pair<string, int>>> favorites;
    Cinema();
    Cinema(string genre, string movie, int price);
    void addGenre(string genre);
    void removeGenre(string genre);
    void editGenre(string genre, string new_genre);
    void addMovie(string genre, string movie, int price);
    void removeMovie(string movie);
    void editMovie(string genre, string movie, string new_movie, int new_price);
    void editPrice(string movie, int new_price);
    void printGenre(string genre);
    void printSortedGenre(string genre);
    void printMovie(string movie);
    void print();
    void favoritesAddGenre(string genre);
    void favoritesRemoveGenre(string genre);
    void favoritesAddMovie(string genre, string movie, int price);
    void favoritesRemoveMovie(string movie);
    void changeOrder(string first_genre, string first_movie, string second_genre, string second_movie);
    void printFavorites();
};

#endif
