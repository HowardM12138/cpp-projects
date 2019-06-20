#include "../my_library/key_press.h"
#include <sstream>

int main() {

    while (1) {
        std::cout << "You pressed: ";
        display_key_pressed(get_key_pressed());
    }

}
