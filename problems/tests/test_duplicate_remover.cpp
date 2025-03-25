#include <gtest/gtest.h>
#include "duplicate_remover.h"

TEST(DuplicateRemoverTest, RemovesDuplicates) {
    std::vector<int> input = {1, 2, 2, 3, 4, 4, 4, 5};
    auto result = DuplicateRemover<int>::removeDuplicates(input);
    
    std::vector<int> expected = {1, 2, 3, 4, 5};
    EXPECT_EQ(result, expected);
}

TEST(DuplicateRemoverTest, EmptyInput) {
    std::vector<int> input;
    auto result = DuplicateRemover<int>::removeDuplicates(input);
    EXPECT_TRUE(result.empty());
}