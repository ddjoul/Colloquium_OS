#include "factorial_generator.h"

std::vector<unsigned long long> FactorialGenerator::generate(unsigned int n) {
    validateInput(n);
    
    std::vector<unsigned long long> result;
    result.reserve(n);
    
    unsigned long long current = 1;
    for (unsigned int i = 1; i <= n; ++i) {
        current *= i;
        result.push_back(current);
    }
    
    return result;
}

void FactorialGenerator::validateInput(unsigned int n) {
    if (n == 0) {
        throw std::invalid_argument("n must be greater than 0");
    }
    if (n > MAX_ALLOWED_N) {
        throw std::invalid_argument("n is too large - would cause overflow");
    }
}