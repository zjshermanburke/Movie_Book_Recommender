cmake_minimum_required (VERSION 3.10)
project(example VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(main main.cpp)

# find_package(PostgreSQL REQUIRED)

# target_link_libraries(main PRIVATE PostgreSQL::PostgreSQL)

# find_package(libpqxx REQUIRED)
# target_link_libraries(main -lpqxx -lpq)