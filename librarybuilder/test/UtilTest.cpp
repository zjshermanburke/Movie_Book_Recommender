#include <gtest/gtest.h>
#include "Util.h"

TEST(UtilTest, ValidTableName) {
    EXPECT_NO_THROW(validate_table_name("my_table"));
}

TEST(UtilTest, InvalidTableName) {
    EXPECT_ANY_THROW(validate_table_name("my;table"));
}

TEST(UtilTest, PrepareTableName) {
    MovieCollection movies("My Movie Collection");
    std::string name = prepare_table_name(movies);
    EXPECT_EQ(name, "My_Movie_Collection");
}
