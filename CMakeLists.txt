cmake_minimum_required(VERSION 3.29)
project(front_sandbox)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(front_sandbox main.cpp
        front/App/App.cpp
        front/App/App.h
        front/ProductCard/ProductCard.cpp
        front/ProductCard/ProductCard.h)
target_link_libraries(front_sandbox
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

