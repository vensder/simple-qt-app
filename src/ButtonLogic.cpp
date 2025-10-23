#include "ButtonLogic.hpp"

std::string ButtonLogic::getAboutMessage() const
{
    return "This is a simple Qt app built with CMake.\nLearn more at qt.io!";
}

int ButtonLogic::incrementClickCount()
{
    return ++clickCount;
}
