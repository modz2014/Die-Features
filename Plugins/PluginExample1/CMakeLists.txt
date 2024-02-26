cmake_minimum_required(VERSION 3.14)

project(pluginexample1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets)

add_library(pluginexample1 SHARED
    pluginexample_global.h
    pluginexample.cpp
    pluginexample.h
    pluginInterFace.h
)

target_link_libraries(pluginexample1 PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Widgets)

target_compile_definitions(pluginexample1 PRIVATE PLUGINEXAMPLE1_LIBRARY)
