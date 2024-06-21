#include "Cinema.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

Cinema::Cinema()
{
    
}

Cinema::Cinema(string genre, string movie, int price)
{
    auto movie_price =  pair<string, int> (movie, price);
    movies.insert(make_pair(genre, movie_price));
}

void Cinema::addGenre(string genre)
{   
    if (movies.find(genre) == movies.end())
    {
        pair<string, int> movie_price;
        movies.insert(make_pair(genre, movie_price));
    }
    
}

void Cinema::removeGenre(string genre)
{
    movies.erase(genre);
}

void Cinema::editGenre(string genre, string new_genre)
{
    for (auto &kv : movies)
    {
        if (kv.first == genre)
        {
            addMovie(new_genre, kv.second.first, kv.second.second);
        }
        
    }

    removeGenre(genre);

}

void Cinema::addMovie(string genre, string movie, int price)
{
    auto it = find_if(movies.begin(), movies.end(), [genre](auto x){return x.first == genre;});
    
    if (it->second.first == "")
    {
        movies.erase(it);
    }

    auto movie_price = pair<string, int> (movie, price);
    movies.insert(make_pair(genre, movie_price));
}

void Cinema::removeMovie(string movie)
{
    string genre;

    for (auto &kv : movies)
    {
        if (kv.second.first == movie)
        {
            genre = kv.first;
            break;
        }
        
    }
    
    typedef multimap<string, pair<string, int>>::iterator iterator;
    std::pair<iterator, iterator> iterpair = movies.equal_range(genre);
    iterator it = iterpair.first;

    for (; it != iterpair.second; ++it) 
    {
        if (it->second.first == movie) 
        { 
            movies.erase(it);
            break;
        }

    }
    
}

void Cinema::editMovie(string genre, string movie, string new_movie, int new_price)
{
    for (auto &kv : movies)
    {
        if (kv.second.first == movie && kv.first == genre)
        {
            kv.second.first = new_movie;
            kv.second.second = new_price;
            return;
        }
        
    }
}

void Cinema::editPrice(string movie, int new_price)
{
    for(auto& kv : movies)
    {
        if (kv.second.first == movie)
        {
            kv.second.second = new_price;
            return;
        }
        
    }
}

void Cinema::print()
{
    string current_key = "";
    
    for (const auto& kv : movies) 
    {
        if (kv.first != current_key) 
        {
            cout << endl;

            if (kv.second.first == "") 
            {
                cout << kv.first << ": " << "\n\t (empty)";
                continue;
            }

            current_key = kv.first;
            cout << kv.first << ": " << "\n\t" << kv.second.first << ": " << kv.second.second;
        } else 
        {
            cout << "\n\t" << kv.second.first << ": " << kv.second.second;
        }
    }

    cout << "\n\n";
}

void Cinema::printGenre(string genre)
{
    string current_key = "";
    
    for (const auto& kv : movies) 
    {
        if (kv.first == genre)
        {
            if (kv.first != current_key) 
            {
                cout << endl;

                if (kv.second.first == "") 
                {
                    cout << ": " << "\n\t (empty)";
                    continue;
                }

                current_key = kv.first;
                cout << ": " << "\n\t" << kv.second.first << ": " << kv.second.second;
            } else 
            {
                cout << "\n\t" << kv.second.first << ": " << kv.second.second;
            }
            
        }
        
    }

    cout << "\n\n";
}

void Cinema::printSortedGenre(string genre)
{
    string current_key = "";
    map<int, string> films;

    for (const auto& kv : movies) 
    {
        if (kv.first == genre)
        {
            films.insert(make_pair(kv.second.second, kv.second.first)); 
        }
        
    }
    
    cout << endl << genre << ":";

    for (auto &kv : films)
    {
        if (kv.second != current_key) 
            {
                if (kv.second == "") 
                {
                    cout << "\n\t (empty)";
                    continue;
                }

                current_key = kv.first;
                cout << "\n\t" << kv.second << ": " << kv.first;
            } else 
            {
                cout << "\n\t" << kv.second << ": " << kv.first;
            }
    }
    
    cout << "\n\n";
}

void Cinema::printMovie(string movie)
{
    string current_key = "";
    
    cout << endl << movie << ": " << endl;

    for (const auto& kv : movies) 
    {
        if (kv.second.first == movie)
        {
            if (kv.first != current_key) 
            {
                current_key = kv.first;
                cout <<"\t" << kv.first << ": " << kv.second.second;
                cout << endl;
            } else 
            {
                cout << "\t" << kv.first << ": " << kv.second.second;
            }
            
        }
        
    }

    cout << endl;
}

void Cinema::favoritesAddGenre(string genre)
{
    if (find_if(favorites.begin(), favorites.end(), [genre](auto x){return x.first == genre;}) == favorites.end())
    {
        auto movie_price = pair<string, int> ("", 0);
        favorites.push_back(make_pair(genre, movie_price));
    }
    
}

void Cinema::favoritesRemoveGenre(string genre)
{
    for (size_t i = 0; i < favorites.size(); i++)
    {
        if (favorites[i].first == genre)
        {
            favorites.erase(favorites.begin() + i);
        }
        
    }
    
}

void Cinema::favoritesAddMovie(string genre, string movie, int price)
{
    for (size_t i = 0; i < favorites.size(); i++)
    {
        if (favorites[i].second.first == "" && favorites[i].first == genre)
        {
            favorites.erase(favorites.begin() + i);
        }

    }

    auto movie_price =  pair<string, int> (movie, price);
    favorites.push_back(make_pair(genre, movie_price));

}

void Cinema::favoritesRemoveMovie(string movie)
{
    for (size_t i = 0; i < favorites.size(); i++)
    {
        if (favorites[i].second.first == movie)
        {
            favorites.erase(favorites.begin() + i);
        }
        
    }
    
}

void Cinema::changeOrder(string first_genre, string first_movie, string second_genre, string second_movie)
{
    auto it1 = find_if(favorites.begin(), favorites.end(), [first_genre](auto x){return x.first == first_genre;});
    auto it2 = find_if(favorites.begin(), favorites.end(), [second_genre](auto x){return x.first == second_genre;});
    
    it1->first = second_genre;
    it1->second.first = second_movie;
    auto temp = it1->second.second;
    it1->second.second = it2->second.second;
    it2->first = first_genre;
    it2->second.first = first_movie;
    it2->second.second = temp;
}

void Cinema::printFavorites()
{
    cout << endl;
    
    for (auto &elem : favorites)
    {
        if (elem.second.first == "")
        {
            cout << "genre: "  << elem.first << " (empty)" << endl;
        } else
        {
            cout << "genre: "  << elem.first << ", movie: " << elem.second.first << ", price: " << elem.second.second << endl;
        }

    }
   
}
