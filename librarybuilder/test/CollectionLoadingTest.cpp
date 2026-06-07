#include <gtest/gtest.h>
#include "MovieCollection.h"
#include "BookCollection.h"
#include "SQLQueryUtil.h"

TEST(CollectionLoadingTest, LoadMovies) {
    DataBaseConnection database;
    database.set_connection();
    MovieCollection collection = load_movie_collection(database, "movie_collection");
    EXPECT_GT(collection.get_movies().size(), 0);
    EXPECT_TRUE(collection.add_movie("Forrest Gump", "PG-13", 1, 3));
    database.disconnect();
}

TEST(CollectionLoadingTest, LoadBooks) {
    DataBaseConnection database;
    database.set_connection();
    BookCollection collection = load_book_collection(database, "bookcollection");
    EXPECT_GT(collection.get_books().size(), 0);
    EXPECT_TRUE(collection.add_book("Jurassic Park", 1, 5,
        "978-0345538987", "Science Fiction", "Horror", "Michael Crichton"));
    database.disconnect();
}
