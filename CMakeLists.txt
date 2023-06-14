cmake_minimum_required(VERSION 3.25)
project(sort_visualization)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(
        Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED
)

add_executable(
        sort_visualization
        main.cpp

        qt/mainwindow.cpp
        qt/mainwindow.h
        qt/mainwindow.ui

        qt/sortingwindow.cpp
        qt/sortingwindow.h
        qt/sortingwindow.ui

        utils/random_generator.cpp
        utils/sorting.cpp
)
target_link_libraries(
        sort_visualization
        Qt::Core
        Qt::Gui
        Qt::Widgets
)
