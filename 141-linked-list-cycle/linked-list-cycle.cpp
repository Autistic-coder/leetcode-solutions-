class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;        // Moves one step
            fast = fast->next->next;  // Moves two steps

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};