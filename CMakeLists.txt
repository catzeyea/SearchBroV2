cmake_minimum_required(VERSION 3.16)
project(SearchBroV2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Aktiviert automatische MOC/UIC/RCC Verarbeitung (muss VOR add_executable stehen!)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Qt6 finden
find_package(Qt6 REQUIRED COMPONENTS Widgets Core Gui Network Test)

# pybind11 finden
find_package(pybind11 REQUIRED)

# Python (Interpreter + Development) finden
find_package(Python COMPONENTS Interpreter Development REQUIRED)

# Executable
add_executable(SearchBroV2
    src/main.cpp
    src/MainWindow.cpp
    src/KIStuff.cpp

)



# Include-Verzeichnis
target_include_directories(SearchBroV2 PRIVATE 
${CMAKE_SOURCE_DIR}/extern/pybind11/include
${Python_INCLUDE_DIRS}
${CMAKE_SOURCE_DIR}/src/include
)

# Qt + pybind11 + Python verlinken
target_link_libraries(SearchBroV2
    PRIVATE
        Qt6::Widgets
        Qt6::Core
        Qt6::Gui
        Qt6::Network
        Qt6::Test
        Python::Python
        
)
message(STATUS "Python include dirs: ${Python_INCLUDE_DIRS}")
message(STATUS "pybind11 include dirs: ${pybind11_INCLUDE_DIRS}")
message(STATUS "Python libraries: ${Python_LIBRARIES}")
