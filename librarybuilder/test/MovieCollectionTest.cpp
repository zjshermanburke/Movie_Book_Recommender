#include <iostream>
#include "../include/MovieCollection.h"
#include "../include/Util.h"
#include "../include/SQLQueryUtil.h"

void movie_functionality_test(DataBaseConnection &database){

    MovieCollection my_movies("movie_collection");
    my_movies.display(); // Displaying empty library should return message

    add_movie(my_movies, "Star Wars", "PG-13", 3, 4);
    my_movies.display();
    add_movie(my_movies, "Django", "R", 2, 5);

    my_movies.display(); // Display Django 2 times watched
    increment_watched(my_movies, "Django");
    my_movies.display(); // Display Django 3 times watched

    increment_watched(my_movies, "Rocky"); // Should return false
    add_movie(my_movies, "Django", "R", 15, 4); // Should return false
    my_movies.display();
    add_movie(my_movies, "Zoolander", "M", 1, 5);
    my_movies.display();
    add_movie(my_movies, "Apples", "PG-13", 0, 5);
    my_movies.display();

    MovieCollection my_movies_deep_copy{my_movies}; // Calls the deep copy constructor

    my_movies_deep_copy.set_name("New Movie Collection");

    std::cout << "Original Movie Collection Name: " << my_movies.get_name() << std::endl;
    std::cout << "Deep Copy Movie Collection Name: " << my_movies_deep_copy.get_name() << std::endl;

    create_table(database, my_movies);
}