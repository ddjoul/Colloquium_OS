#include <gtest/gtest.h>
#include "list_reverser.h"

TEST(ListReverserTest, ReversesList) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    
    auto reversed = ListReverser::reverse(head);
    
    EXPECT_EQ(reversed->val, 3);
    EXPECT_EQ(reversed->next->val, 2);
    EXPECT_EQ(reversed->next->next->val, 1);
    EXPECT_EQ(reversed->next->next->next, nullptr);
    
    // Cleanup
    delete reversed->next->next;
    delete reversed->next;
    delete reversed;
}

TEST(ListReverserTest, EmptyList) {
    EXPECT_EQ(ListReverser::reverse(nullptr), nullptr);
}