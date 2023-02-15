#include "bigint.hpp"
#include <iostream>

void print_usage(std::string bin_name) {
    std::cout << bin_name << " [num1] [num2]" << std::endl;
}

static const int BASE = 1000000;

int main(int argc, char **argv) {
    if (argc != 3) {
        print_usage(argv[0]);
        return 1;
    }

    BigInt<BASE> v1(argv[1]);
    BigInt<BASE> v2(argv[2]);

    std::cout << (v1 + v2).to_string() << std::endl;


}
