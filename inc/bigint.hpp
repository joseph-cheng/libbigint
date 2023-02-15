#pragma once

#include <cstdint>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

template <uint32_t base> class BigInt {
    static_assert(base > 1, "Base must be > 1");
  private:
    std::vector<uint64_t> digits;

    uint64_t operator[](size_t idx) {
        if (idx >= digits.size()) {
            return 0;
        }
        return digits[idx];
    }

  public:
    BigInt(uint64_t val) {
        while (val > 0) {
            digits.push_back(val % base);
            val /= base;
        }
    }

    BigInt(std::string num) {
        int pow10 = pow10_base();
        if (pow10 == -1) {
            throw std::runtime_error("Base is not power of 10, unimplemented");
        }

        int end = num.length();

        while (end > 0) {
            size_t start = end - pow10 < 0 ? 0 : end - pow10;
            std::string portion = num.substr(start, end - start);
            digits.push_back(std::stoull(portion));
            end -= pow10;
        }
        

    }

    BigInt operator+(BigInt &rhs) {
        BigInt<base> ret(0);
        size_t ii = 0;
        uint64_t carry = 0;
        uint64_t add1 = rhs[ii];
        uint64_t add2 = (*this)[ii];
        while (carry != 0 || add1 != 0 || add2 != 0) {
            ii++;
            uint64_t tmp = add1 + add2 + carry;
            carry = tmp / base;
            ret.digits.push_back(tmp % base);
            add1 = rhs[ii];
            add2 = (*this)[ii];
        }
        return ret;
    }

    int pow10_base() {
        switch (static_cast<uint64_t>(base)) {
        case 10:
            return 1;
        case 100:
            return 2;
        case 1000:
            return 3;
        case 10000:
            return 4;
        case 100000:
            return 5;
        case 1000000:
            return 6;
        case 10000000:
            return 7;
        case 100000000:
            return 8;
        case 1000000000:
            return 9;
        case 10000000000:
            return 10;
        case 100000000000:
            return 11;
        case 1000000000000:
            return 12;
        case 10000000000000:
            return 13;
        case 100000000000000:
            return 14;
        case 1000000000000000:
            return 15;
        case 10000000000000000:
            return 16;
        case 100000000000000000:
            return 17;
        case 1000000000000000000:
            return 18;
        case 10000000000000000000:
            return 19;
        default:
            return -1;
        }
    }

    std::string to_string() {
        int pow10 = pow10_base();
        if (pow10 == -1) {
            throw std::runtime_error("Base is not power of 10, unimplemented");
        }
        std::stringstream out;
        bool first = true;
        for (auto it = digits.rbegin(); it != digits.rend(); it++) {
            auto digit = *it;
            if (first) {
                out << digit;
                first = false;
            }
            else {
                out << std::setw(pow10) << std::setfill('0') << digit;
            }
            //out << ",";
        }
        return out.str();
    }
};
