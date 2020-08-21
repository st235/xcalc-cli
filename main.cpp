#include <string>
#include <iostream>
#include <unordered_map>
#include "./libs/xcalc/include/xcalc.h"

namespace  {

bool ContainsKey(const std::unordered_map<std::string, std::string>& args, const std::string& arg) {
    return args.find(arg) != args.end();
}

std::string GetOrDefault(std::unordered_map<std::string, std::string>& args, const std::string& arg, const std::string& def) {
    if (!ContainsKey(args, arg)) {
        return def;
    }

    return args[arg];
}

void PrintHelp() {
    std::cout << "-A angle mode, could be: RADS (stands for radians), DEG (stands for degrees)" << std::endl
              << "-e evaluate given expression" << std::endl
              << "-h help" << std::endl;
}

xcalc::DegreeMode ToDegreeMode(const std::string& mode) {
    if (mode == "RADS") {
        return xcalc::DegreeMode::RADS;
    }

    return xcalc::DegreeMode::DEG;
}

}

int main(int argc, char* argv[]) {
    std::unordered_map<std::string, std::string> args;

    for (int i = 1; i < argc; i++) {
        std::string arg(argv[i]);

        if (arg == "-h") {
            args[arg] = "";
            continue;
        }

        if (i < argc - 1) {
            std::string nextArg(argv[i + 1]);
            args[arg] = nextArg;
            i++;
        }
    }

    if (ContainsKey(args, "-h")) {
        PrintHelp();
        return 0;
    }

    xcalc::DegreeMode degreeMode = ToDegreeMode(GetOrDefault(args, "-A", "DEG"));

    if (ContainsKey(args, "-e")) {
        std::cout << xcalc::evaluate(degreeMode, GetOrDefault(args, "-e", "")) << std::endl;
        return 0;
    }

    std::cout << "Welcome at xcalc command line interface: " << std::endl;
    std::string user_input = "";
    while (true) {
        std::cout << " > ";
        std::getline(std::cin, user_input);

        if (user_input == "q") {
            std::cout << "goodbye" << std::endl;
            break;
        }

        std::cout << xcalc::evaluate(degreeMode, user_input) << std::endl;
    }

    return 0;
}

