#pragma once
#include <string>

class ButtonLogic {
public:
    ButtonLogic() = default;
    std::string getAboutMessage() const;
    int incrementClickCount();
private:
    int clickCount = 0;
};
