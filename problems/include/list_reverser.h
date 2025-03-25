#pragma once

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class ListReverser {
public:
    static ListNode* reverse(ListNode* head);
    
private:
    static ListNode* reverseRecursive(ListNode* current, ListNode* prev);
};