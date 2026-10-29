class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prevGroup = &dummy;

        while (true) {
            ListNode* kth = prevGroup;

            for (int i = 0; i < k && kth != nullptr; i++) {
                kth = kth->next;
            }

            if (kth == nullptr)
                break;

            ListNode* groupNext = kth->next;
            ListNode* prev = groupNext;
            ListNode* curr = prevGroup->next;

            while (curr != groupNext) {
                ListNode* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }

            ListNode* oldStart = prevGroup->next;
            prevGroup->next = kth;
            prevGroup = oldStart;
        }

        return dummy.next;
    }
};