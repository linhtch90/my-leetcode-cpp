//
// Created by boris on 12/29/25.
//

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        if (head == nullptr) {
            return nullptr;
        }
        bool isCycle = false;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                isCycle = true;
                break;
            }
        }
        if (!isCycle) {
            return nullptr;
        }
        ListNode *countPointer = slow->next;
        int cycleCount = 1;
        while (countPointer != slow) {
            cycleCount++;
            countPointer = countPointer->next;
        }
        ListNode *pointer1 = head;
        ListNode *pointer2 = head;
        for (int i = 0; i < cycleCount; i++) {
            pointer1 = pointer1->next;
        }
        while (pointer1 != pointer2) {
            pointer1 = pointer1->next;
            pointer2 = pointer2->next;
        }
        return pointer1;
    }
};