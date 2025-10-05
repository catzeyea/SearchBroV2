cmake_minimum_required(VERSION 3.16)
project(MyCppProject VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include-Verzeichnis
include_directories(include)

# Executable erstellen
add_executable(SearchBro src/main.cpp)
