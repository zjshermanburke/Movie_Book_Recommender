#include <iostream>
#include "../include/MovieCollection.h"

using namespace std;

// Function prototypes
void increment_watched(MovieCollection &movies, std::string title);
void add_movie(MovieCollection &movie, string name, string mpa_rating, int watched, int rating);

// Helper functions
// Helper fucntion to increment the movie watched count
void increment_watched(MovieCollection &movies, string title){
    if (movies.increment_watched(title)){
        cout << title << " watched incremented" << endl;
    } else {
        cout << title << " not found" << endl;
    }
}
// Helper function to add movie
void add_movie(MovieCollection &movies, string title, string mpa_rating, int watched, int rating){
    if (movies.add_movie(title, mpa_rating, watched, rating)){
        cout << title << " added to library" << endl;
    } else {
        cout << title << " is already in library" << endl;
    }
}

int main(){
    MovieCollection my_movies;
    my_movies.display(); // Displaying empty library should return message

    my_movies.add_movie("Star Wars", "PG-13", 3, 4);
    my_movies.display();
    my_movies.add_movie("Django", "R", 2, 5);

    my_movies.display(); // Display Django 2 times watched
    my_movies.increment_watched("Django");
    my_movies.display(); // Display Django 3 times watched

    my_movies.increment_watched("Rocky"); // Should return false
    my_movies.add_movie("Django", "R", 15, 4); // Should return false
    my_movies.display();
    my_movies.add_movie("Zoolander", "M", 1, 5);
    my_movies.display();
    my_movies.add_movie("Apples", "PG-13", 0, 5);
    my_movies.display();

    MovieCollection my_movies_deep_copy{my_movies}; // Calls the deep copy constructor
    
    return 0;
}
