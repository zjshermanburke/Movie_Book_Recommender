#include <gtest/gtest.h>
#include "MovieCollection.h"
#include "Util.h"

TEST(MovieCollectionTest, EmptyCollection){
    MovieCollection my_movies("Movie Collection");
    EXPECT_EQ(my_movies.get_movies().size(), 0);
}

TEST(MovieCollectionTest, AddToEmpty) {
    MovieCollection movies("Test");
    EXPECT_TRUE(movies.add_movie("Inception", "PG-13", 2, 5));
    EXPECT_EQ(movies.get_movies()[0].get_title(), "Inception");
}

TEST(MovieCollectionTest, AddAtBeginning) {
    MovieCollection movies("Test");
    movies.add_movie("The Matrix", "R", 3, 5);
    movies.add_movie("Alien", "R", 1, 4);
    EXPECT_EQ(movies.get_movies()[0].get_title(), "Alien");
}

TEST(MovieCollectionTest, AddInMiddle) {
    MovieCollection movies("Test");
    movies.add_movie("Alien", "R", 1, 4);
    movies.add_movie("The Matrix", "R", 3, 5);
    movies.add_movie("Gladiator", "R", 2, 4);
    EXPECT_EQ(movies.get_movies()[1].get_title(), "Gladiator");
}

TEST(MovieCollectionTest, AddAtEnd) {
    MovieCollection movies("Test");
    movies.add_movie("Alien", "R", 1, 4);
    movies.add_movie("The Matrix", "R", 3, 5);
    EXPECT_EQ(movies.get_movies().back().get_title(), "The Matrix");
}

TEST(MovieCollectionTest, AddDuplicate) {
    MovieCollection movies("Test Collection");
    movies.add_movie("Django", "R", 2, 5);
    EXPECT_FALSE(movies.add_movie("Django", "R", 15, 4));
    EXPECT_EQ(movies.get_movies().size(), 1);
}

TEST(MovieCollectionTest, IncrementWatched) {
    MovieCollection movies("Test Collection");
    movies.add_movie("Django", "R", 2, 5);
    EXPECT_TRUE(movies.increment_watched("Django"));
    EXPECT_FALSE(movies.increment_watched("Rocky"));
}

TEST(MovieCollectionTest, LexicographicOrder) {
    MovieCollection movies("Test Collection");
    movies.add_movie("Zoolander", "M", 1, 5);
    movies.add_movie("Apples", "PG-13", 0, 5);
    movies.add_movie("Django", "R", 2, 5);
    auto list = movies.get_movies();
    EXPECT_EQ(list[0].get_title(), "Apples");
    EXPECT_EQ(list[1].get_title(), "Django");
    EXPECT_EQ(list[2].get_title(), "Zoolander");
}

TEST(MovieCollectionTest, DeepCopy) {
    MovieCollection movies("Test Collection");
    movies.add_movie("Star Wars", "PG-13", 3, 4);
    MovieCollection copy(movies);
    copy.add_movie("Django", "R", 2, 5);
    EXPECT_EQ(movies.get_movies().size(), 1);
    EXPECT_EQ(copy.get_movies().size(), 2);
}