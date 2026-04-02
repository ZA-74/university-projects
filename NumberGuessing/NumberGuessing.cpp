#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    int secret = rand() % 100 + 1;
    int guess;
    int tries = 0;

    std::cout << "Guess a number from 1 to 100:\n";

    do {
        std::cin >> guess;
        tries++;

        if (guess < secret)
            std::cout << "Too low\n";
        else if (guess > secret)
            std::cout << "Too high\n";
        else
            std::cout << "Correct! Tries: " << tries << "\n";
    } while (guess != secret);

    return 0;
}
