#include <iostream>
#include "../include/MovieCollection.h"
#include "../include/BookCollection.h"
#include "../include/Util.h"

void simplified_test(){

    MovieCollection my_movies("Movie Collection");
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

    //std::string title, int times_read, int user_rating, std::string isbn, std::string genre, std::string sub_genre
    BookCollection my_books("Test Collection");
    my_books.display(); // Displaying empty library should return message

    add_book(my_books, "C++ Programming Language", 3, 5, "978-0321958327", "Non-fiction", "Instructional", "Bjarne Stroustrup");
    my_books.display();
    add_book(my_books, "Paradise Lost", 1, 4, "978-0140424393", "Fiction", "Epic Poem", "John Milton");

    my_books.display(); // Display Test_Book2 0 times watched
    increment_read(my_books, "Paradise Lost");
    my_books.display(); // Display Test_Book2 1 times watched

    increment_read(my_books, "Test_Book6"); // Should return false
    add_book(my_books, "The C Programming Language", 0, 5, "978-0131103627", "Non-fictional", "Instructional", "Brian W. Kernighan");
    my_books.display();
    add_book(my_books, "1984", 0, 2, "978-6257287401", "Fiction", "Dystopian Fiction","George Orwell");
    my_books.display();

    BookCollection my_books_deep_copy{my_books}; // Calls the deep copy constructor
}