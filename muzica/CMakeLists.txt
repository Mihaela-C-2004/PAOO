# Versiunea minima de CMake
cmake_minimum_required(VERSION 3.10)

# Numele proiectului
project(muzica)

# Standardul C++
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Unde se cauta fisierele header
include_directories(inc)

# Executabilul si fisierele lui
add_executable(${PROJECT_NAME}
               inc/model/artist.hpp
               inc/model/melodie.hpp
               inc/colectie/playlist.hpp
               inc/utilizator/utilizator.hpp
               inc/demo/exemple_gresite.hpp
               src/model/artist.cpp
               src/model/melodie.cpp
               src/colectie/playlist.cpp
               src/utilizator/utilizator.cpp
               src/demo/exemple_gresite.cpp
               src/main.cpp)
