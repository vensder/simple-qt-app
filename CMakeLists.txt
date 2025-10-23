cmake_minimum_required(VERSION 3.16)

project(SimpleQtApp VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable automatic MOC (Meta-Object Compiler) for Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Find Qt5 package with Widgets module
find_package(Qt5 COMPONENTS Widgets REQUIRED)

# Add the executable
add_executable(SimpleQtApp src/main.cpp)

# Link Qt libraries
target_link_libraries(SimpleQtApp PRIVATE Qt5::Widgets)