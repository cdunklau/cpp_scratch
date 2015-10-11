#include <iostream>

// Output numbers, replacing number divisible by three with "Fizz",
// numbers divisible by 5 with "Buzz", and numbers divisible by both
// 3 and 5 with "FizzBuzz".



int main() {
    for (int i = 1; i <= 100; i++) {
        bool fizzed_or_buzzed = false;
        if (i % 3 == 0) {
            std::cout << "Fizz";
            fizzed_or_buzzed = true;
        }
        if (i % 5 == 0) {
            std::cout << "Buzz";
            fizzed_or_buzzed = true;
        }

        if (!fizzed_or_buzzed) {
            std::cout << i;
        }
        std::cout << std::endl;
    }
    return 0;
}
