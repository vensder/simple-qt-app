# Add test executable
add_executable(TestSimpleQtApp
    test_ButtonLogic.cpp
    ../src/ButtonLogic.cpp
)

# Include directories for tests
target_include_directories(TestSimpleQtApp PRIVATE
    ../src
    ../external/Catch2
)

# Add test to CTest
add_test(NAME TestSimpleQtApp COMMAND TestSimpleQtApp)
