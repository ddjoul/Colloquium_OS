#pragma once

#include <vector>
#include <unordered_set>
#include <algorithm>

template <typename T>
class DuplicateRemover {
public:
    static std::vector<T> removeDuplicates(const std::vector<T>& input);
};

#include "duplicate_remover.tpp"