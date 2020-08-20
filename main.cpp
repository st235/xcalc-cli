#include <string>
#include <iostream>
#include "./libs/xcalc/include/xcalc.h"

int main() {
    std::cout << "Welcome at xcalc command line interface: " << std::endl;
    std::string user_input = "";
    while (true) {
        std::cout << " > ";
        std::cin >> user_input;

        if (user_input == "q") {
            std::cout << "goodbye" << std::endl;
            break;
        }

        std::cout << xcalc::evaluate(user_input) << std::endl;
    }

    return 0;
}
