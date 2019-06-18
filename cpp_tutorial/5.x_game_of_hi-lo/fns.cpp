#include "fns.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

void start() {
    int random_number = get_random_number(0, 100);
    int tries = 0;
    bool won = false;
    std::cout << "Let's play a game. I'm thinking of a number. You have 7 "
        "tries to guess what it is.\n";
    while (tries < 7) {
        if (user_guess(tries, random_number)) {
            won = win();
            break;
        }
        tries++;
    }
    if (!won) {
        lose(random_number);
    }
    end();
}

int get_random_number(int min, int max) {
    srand(time(0));
    double fraction = rand() / (RAND_MAX + 1.0);
    double random_number = min + (max - min + 1) * fraction;
    return static_cast<int>(random_number);
}

bool user_guess(int tries, int answer) {
    int guess;

    std::cout << "Guess #" << tries + 1 << ": ";
    std::cin >> guess;
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(32768, '\n');

        std::cout << "Please enter a valid input.\n";
        std::cout << "Guess #" << tries + 1 << ": ";
        std::cin >> guess;
    }
    std::cin.ignore(32768, '\n');

    if (guess == answer) {
        return true;
    } else if (guess < answer) {
        std::cout << "Your guess is too low\n";
    } else {
        std::cout << "Your guess is too high\n";
    }

    return false;
}

bool win() {
    std::cout << "Correct! You Won!\n\n";
    return true;
}

void lose(int answer) {
    std::cout << "Sorry, you lose. The correct number was " << answer <<  ".\n\n";
}

void end() {
    if (restart()) start();
    else {
        std::cout << "Thank you for playing.\n";
    }
}

bool restart() {
    std::string response;

    std::cout << "Would you like to play again? (y/n): ";
    std::cin >> response;
    while (response != "y" && response != "n") {
        std::cout << "Please enter y/n: ";
        std::cin >> response;
    }
    std::cout << "\n";

    if (response == "y") return true;
    return false;
}
