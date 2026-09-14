#include "armstrong_numbers.h"
#include <cmath>
#include <string>

namespace armstrong_numbers {

bool is_armstrong_number(int number) {
    std::string s = std::to_string(number);
    int num_digits = s.length();
    long long sum = 0;
    
    for (char c : s) {
        int digit = c - '0';
        sum += std::pow(digit, num_digits);
    }
    
    return sum == number;
}

}  // namespace armstrong_numbers
