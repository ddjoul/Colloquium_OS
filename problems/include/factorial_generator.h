#pragma once

#include <vector>
#include <stdexcept>

class FactorialGenerator {
public:
    static std::vector<unsigned long long> generate(unsigned int n);
    
private:
    static void validateInput(unsigned int n);
    static const unsigned int MAX_ALLOWED_N = 20;
};