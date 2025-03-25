#include "list_reverser.h"

ListNode* ListReverser::reverse(ListNode* head) {
    return reverseRecursive(head, nullptr);
}

ListNode* ListReverser::reverseRecursive(ListNode* current, ListNode* prev) {
    if (current == nullptr) {
        return prev;
    }
    
    ListNode* next = current->next;
    current->next = prev;
    
    return reverseRecursive(next, current);
}