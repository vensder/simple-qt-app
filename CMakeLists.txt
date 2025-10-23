cmake_minimum_required(VERSION 3.16)

project(SimpleQtApp VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable automatic MOC for Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Find Qt5 package
find_package(Qt5 COMPONENTS Widgets REQUIRED)

# Add include directories
include_directories(${Qt5Widgets_INCLUDE_DIRS})

# Add source files
add_executable(SimpleQtApp
    src/main.cpp
    src/ButtonLogic.cpp
)

# Link Qt libraries
target_link_libraries(SimpleQtApp PRIVATE Qt5::Widgets)

# Include directories for source files
target_include_directories(SimpleQtApp PRIVATE src)

# Add tests subdirectory
enable_testing()
add_subdirectory(tests)
