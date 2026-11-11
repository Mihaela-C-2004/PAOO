# Versiunea minima de CMake
cmake_minimum_required(VERSION 3.10)

# Numele proiectului
project(biblioteca)

# Standardul C++
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Unde se cauta fisierele header
include_directories(inc)

# Executabilul si fisierele lui
add_executable(${PROJECT_NAME}
               inc/util/registru.hpp
               inc/model/carte.hpp
               inc/model/carte_digitala.hpp
               inc/imprumut/imprumut.hpp
               inc/cititor/permis_cititor.hpp
               inc/demo/exemple_gresite.hpp
               src/util/registru.cpp
               src/model/carte.cpp
               src/model/carte_digitala.cpp
               src/imprumut/imprumut.cpp
               src/cititor/permis_cititor.cpp
               src/demo/exemple_gresite.cpp
               src/main.cpp)
