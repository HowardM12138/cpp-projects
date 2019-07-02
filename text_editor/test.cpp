#include "../my_library/key_press.h"

int main() {
    std::string str = "this is str";
    std::string trail = "";
    for (int i = 0; i < 81; i++) {
        trail += "a";
    }
    //trail += "this is what's after the trail";
    std::cout << trail << "\n";
    std::cout << trail.find("\n") << "\n";
}
