#include <gtest/gtest.h>
#include "BookCollection.h"
#include "Util.h"

TEST(BookCollectionTest, EmptyCollection) {
    BookCollection books("Test Collection");
    EXPECT_EQ(books.get_books().size(), 0);
}
TEST(BookCollectionTest, AddToEmpty) {
    BookCollection books("Test");
    EXPECT_TRUE(books.add_book("Dune", 2, 5, "978-0441172719", "Science Fiction", "Space Opera", "Frank Herbert"));
    EXPECT_EQ(books.get_books()[0].get_title(), "Dune");
}

TEST(BookCollectionTest, AddAtBeginning) {
    BookCollection books("Test");
    books.add_book("The Hobbit", 3, 5, "978-0547928227", "Fiction", "Fantasy", "J.R.R. Tolkien");
    books.add_book("Brave New World", 1, 4, "978-0060850524", "Fiction", "Dystopian", "Aldous Huxley");
    EXPECT_EQ(books.get_books()[0].get_title(), "Brave New World");
}

TEST(BookCollectionTest, AddInMiddle) {
    BookCollection books("Test");
    books.add_book("Brave New World", 1, 4, "978-0060850524", "Fiction", "Dystopian", "Aldous Huxley");
    books.add_book("The Hobbit", 3, 5, "978-0547928227", "Fiction", "Fantasy", "J.R.R. Tolkien");
    books.add_book("Dune", 2, 5, "978-0441172719", "Science Fiction", "Space Opera", "Frank Herbert");
    EXPECT_EQ(books.get_books()[1].get_title(), "Dune");
}

TEST(BookCollectionTest, AddAtEnd) {
    BookCollection books("Test");
    books.add_book("Brave New World", 1, 4, "978-0060850524", "Fiction", "Dystopian", "Aldous Huxley");
    books.add_book("The Hobbit", 3, 5, "978-0547928227", "Fiction", "Fantasy", "J.R.R. Tolkien");
    EXPECT_EQ(books.get_books().back().get_title(), "The Hobbit");
}

TEST(BookCollectionTest, AddDuplicate) {
    BookCollection books("Test Collection");
    books.add_book("1984", 0, 2, "978-6257287401", "Fiction",
        "Dystopian Fiction", "George Orwell");
    EXPECT_FALSE(books.add_book("1984", 1, 3, "978-6257287401", "Fiction",
        "Dystopian Fiction", "George Orwell"));
    EXPECT_EQ(books.get_books().size(), 1);
}

TEST(BookCollectionTest, IncrementRead) {
    BookCollection books("Test Collection");
    books.add_book("Paradise Lost", 1, 4,
        "978-0140424393", "Fiction", "Epic Poem", "John Milton");
    EXPECT_TRUE(books.increment_read("Paradise Lost"));
    EXPECT_FALSE(books.increment_read("Test_Book6"));
}

TEST(BookCollectionTest, LexicographicOrder) {
    BookCollection books("Test Collection");
    books.add_book("Paradise Lost", 1, 4, "978-0140424393", "Fiction", "Epic Poem", "John Milton");
    books.add_book("1984", 0, 2, "978-6257287401", "Fiction", "Dystopian Fiction", "George Orwell");
    books.add_book("C++ Programming Language", 3, 5, "978-0321958327", "Non-fiction", "Instructional", "Bjarne Stroustrup");
    auto list = books.get_books();
    EXPECT_EQ(list[0].get_title(), "1984");
    EXPECT_EQ(list[1].get_title(), "C++ Programming Language");
    EXPECT_EQ(list[2].get_title(), "Paradise Lost");
}

TEST(BookCollectionTest, DeepCopy) {
    BookCollection books("Test Collection");
    books.add_book("1984", 0, 2, "978-6257287401", "Fiction",
        "Dystopian Fiction", "George Orwell");
    BookCollection copy(books);
    copy.add_book("Paradise Lost", 1, 4,
        "978-0140424393", "Fiction", "Epic Poem", "John Milton");
    EXPECT_EQ(books.get_books().size(), 1);
    EXPECT_EQ(copy.get_books().size(), 2);
}
