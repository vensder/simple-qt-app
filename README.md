# Simple Qt-based project for Ubuntu with KDE.
Qt is a great choice for GUI development as it's native to KDE and well-supported. 
We'll start with a very simple C++ application using Qt: a window with two buttons ("OK" and "About"). The "OK" button will close the window, and the "About" button will display a simple message box. This will help you get familiar with CMake basics like project setup, finding dependencies (Qt), compiling C++ sources, and building executables.
For now, focus on getting this running to learn the build process with CMake.

## Prerequisites

- Install Qt development packages on Ubuntu (if not already done):

```sh
sudo apt update
sudo apt install qtbase5-dev qttools5-dev-tools cmake g++ build-essential
```

- This gives you Qt 5 (default on many Ubuntu versions; if you prefer Qt 6, adjust packages to `qt6-base-dev` etc., but we'll use Qt 5 for simplicity as it's widely used).
- CMake (version 3.16+ recommended).

## Project Structure

```sh
simple-qt-app/
├── CMakeLists.txt
└── src/main.cpp
```

## Build and Run the Project

From the simple-qt-app directory:

- Create a build directory (good practice to keep source clean):

```sh
mkdir build
cd build
```

- Run CMake to generate build files:

```sh
cmake ..
```

This checks for Qt and sets up the project. If Qt isn't found, ensure paths are correct (e.g., add `export CMAKE_PREFIX_PATH=/usr/lib/x86_64-linux-gnu/cmake/Qt5` if needed).


- Build the executable:

```sh
make
```

Or `cmake --build .` for portability.

- Run it:

`text./SimpleQtApp`

You should see a window with "OK" and "About" buttons.
