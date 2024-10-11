cmake_minimum_required(VERSION 3.29)
project(storage_model)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(storage_model main.cpp
        front/App/App.cpp
        front/App/App.h
        front/ProductCard/ProductCard.cpp
        front/ProductCard/ProductCard.h)
target_link_libraries(storage_model
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

