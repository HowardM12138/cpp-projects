#include "key_press.h"
#include <sstream>

int main() {
    /*
    std::ostringstream s;
    s << "Hello        ";
    std::string string = s.str();
    std::cout << string << ".";
    */

    std::string str;
    std::cout << "Enter your name: ";
    std::cin >> str;
    std::cout << str;
}
