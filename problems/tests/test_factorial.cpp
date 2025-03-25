#include <gtest/gtest.h>
#include "factorial_generator.h"

TEST(FactorialTest, GeneratesCorrectly) {
    auto result = FactorialGenerator::generate(5);
    ASSERT_EQ(result.size(), 5);
    EXPECT_EQ(result[0], 1);
    EXPECT_EQ(result[1], 2);
    EXPECT_EQ(result[2], 6);
    EXPECT_EQ(result[3], 24);
    EXPECT_EQ(result[4], 120);
}

TEST(FactorialTest, ThrowsOnInvalidInput) {
    EXPECT_THROW(FactorialGenerator::generate(0), std::invalid_argument);
    EXPECT_THROW(FactorialGenerator::generate(21), std::invalid_argument);
}