cmake_minimum_required (VERSION 3.10)
project(librarybuilder VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Test Coverage
option(COVERAGE "Enable test coverage" OFF)
if(COVERAGE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif()

find_package(PkgConfig REQUIRED)
pkg_check_modules(PQXX REQUIRED libpqxx)

set(LIB_SOURCES
src/Media.cpp
src/MediaCollection.cpp
src/Movie.cpp
src/MovieCollection.cpp
src/Book.cpp
src/BookCollection.cpp
src/DataBaseConnection.cpp
src/SQLQueryUtil.cpp
src/Util.cpp)

# Main Exectuable
add_executable(main src/main.cpp ${LIB_SOURCES})
target_include_directories(main PRIVATE include ${PQXX_INCLUDE_DIRS})
target_link_libraries(main ${PQXX_LIBRARIES})


# Test Exectuable
find_package(GTest REQUIRED)
add_executable(tests
    test/MovieCollectionTest.cpp
    test/BookCollectionTest.cpp
    test/CollectionLoadingTest.cpp
    test/UtilTest.cpp
    ${LIB_SOURCES}
)

target_include_directories(tests PRIVATE include ${PQXX_INCLUDE_DIRS})
target_link_libraries(tests GTest::GTest GTest::Main ${PQXX_LIBRARIES})

enable_testing()
add_test(NAME AllTests COMMAND tests)