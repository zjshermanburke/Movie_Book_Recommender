#include <iostream>
#include "../include/BookCollection.h"
#include "../include/Util.h"
#include "../include/SQLQueryUtil.h"

void book_functionality_test(DataBaseConnection &database){

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
    std::cout << my_books_deep_copy.get_name() << std::endl;

    create_table(database, my_books);
}