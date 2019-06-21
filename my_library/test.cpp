#include "key_press.h"

int main() {

    while (1) {
        std::cout << "You pressed: " << get_key_pressed_str(get_key_pressed()) << "\n";
    }
    
}
