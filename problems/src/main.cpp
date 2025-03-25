#include <iostream>
#include "factorial_generator.h"
#include "duplicate_remover.h"
#include "list_reverser.h"

int main() {
    // 1. Генерация факториалов
    try {
        auto factorials = FactorialGenerator::generate(5);
        std::cout << "Factorials: ";
        for (auto f : factorials) std::cout << f << " ";
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // 2. Удаление дубликатов
    std::vector<int> numbers = {1, 2, 2, 3, 4, 4, 5};
    auto unique = DuplicateRemover<int>::removeDuplicates(numbers);
    std::cout << "Unique numbers: ";
    for (auto n : unique) std::cout << n << " ";
    std::cout << std::endl;

    // 3. Разворот списка
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    auto reversed = ListReverser::reverse(head);
    std::cout << "Reversed list: ";
    for (auto node = reversed; node != nullptr; node = node->next) {
        std::cout << node->val << " ";
    }
    std::cout << std::endl;

    // Cleanup
    while (reversed != nullptr) {
        ListNode* temp = reversed;
        reversed = reversed->next;
        delete temp;
    }

    return 0;
}