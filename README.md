# Simple Qt-based Project for Ubuntu with KDE

This is a simple C++ project using Qt 5 and CMake, designed to help learn CMake through a pet project. It creates a GUI window with two buttons: "OK" (closes the app) and "About" (shows a message box). The project includes unit tests with Catch2 and a GitHub Actions CI pipeline to automate building and testing.

This project is a foundation for a future typing tutor application, with a focus on learning CMake basics like project setup, dependency management, and testing.

## Features

- Qt 5 GUI with two buttons (OK and About).
- CMake-based build system.
- Unit tests for non-GUI logic using Catch2.
- Continuous Integration (CI) with GitHub Actions to build and test on Ubuntu.

## Prerequisites

- **Ubuntu with KDE** (tested on Ubuntu 22.04).
- Install required packages:

```sh
sudo apt update
sudo apt install -y qtbase5-dev qttools5-dev-tools cmake g++ build-essential
```

- CMake: Version 3.16 or higher.
- Catch2: Included in `external/Catch2/catch.hpp` (downloaded automatically by CI or manually as needed).
- Qt 5: Default for this project (Qt 6 requires package changes, e.g., `qt6-base-dev`).

## Project Structure

```sh
simple-qt-app/
├── CMakeLists.txt           # Root CMake configuration
├── src/                    # Source files
│   ├── main.cpp            # Main Qt application
│   ├── ButtonLogic.hpp     # Logic class for button actions
│   ├── ButtonLogic.cpp     # Implementation of ButtonLogic
├── tests/                  # Unit tests
│   ├── CMakeLists.txt      # Test-specific CMake configuration
│   ├── test_ButtonLogic.cpp # Tests for ButtonLogic
├── external/               # External dependencies
│   ├── Catch2/catch.hpp    # Catch2 testing framework
└── .github/workflows/       # CI pipeline
    ├── ci.yml              # GitHub Actions workflow
```

## Build and Run the Project

Clone the repository:

```sh
git clone <repository-url>
cd simple-qt-app
```

Create a build directory:

```sh
mkdir build
cd build
```

Configure CMake:

```sh
cmake ..
```

If Qt isn't found, set the path:

```sh
export CMAKE_PREFIX_PATH=/usr/lib/x86_64-linux-gnu/cmake/Qt5
cmake ..
```

Build the project:

```sh
make
```

Or use `cmake --build .` for portability.

Run the application:

```sh
./SimpleQtApp
```

You should see a window with "OK" and "About" buttons. Click "OK" to exit, or "About" to see a message.

## Running Tests

The project includes unit tests for the ButtonLogic class using Catch2.

From the build directory, run:

```sh
ctest -V
```

Or run the test executable directly for detailed output:

```sh
./tests/TestSimpleQtApp
```

Expected output: All tests should pass (e.g., 3 assertions in 2 test cases).

## Continuous Integration

This project uses GitHub Actions for CI. The workflow (`ci.yml`) runs on every push or pull request to the main branch, performing:

- Installation of Qt5, CMake, and build tools.
- Downloading Catch2.
- Building the app and tests.
- Running tests with CTest.

Check the Actions tab in the GitHub repository to view build/test results.

## Troubleshooting

- Qt not found? Ensure Qt5 is installed and set `CMAKE_PREFIX_PATH` as above.
- Catch2 issues? Verify `external/Catch2/catch.hpp` exists or re-download:

```sh
mkdir -p external/Catch2
wget -O external/Catch2/catch.hpp https://github.com/catchorg/Catch2/releases/download/v2.13.10/catch.hpp
```

- Build errors? Clear the build directory and retry:

```sh
rm -rf build/*
cmake ..
make
```
