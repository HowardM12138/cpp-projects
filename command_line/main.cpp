#include "class.h"
#include "platform.h"

int main() {


    std::cout << "\n\033[1;91mCommand line operating.\033[0m\n\n";

    start();
    user_input();

    std::cout << "\n\033[1;91mCommand line terminated.\033[0m\n\n";
    return 0;
}
