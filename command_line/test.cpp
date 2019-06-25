#include "../my_library/key_press.h"
#include <sstream>

int main() {

    /*
    while (1) {
        std::cout << "You pressed: " << get_key_pressed_str(get_key_pressed()) << "\n";
    }
    */

    std::string str = "hello world\n";
    std::cout << str.substr(str.size() - 1) << "\n";
}
