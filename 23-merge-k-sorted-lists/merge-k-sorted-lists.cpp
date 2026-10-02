#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) const {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;

        for (ListNode* head : lists) {
            if (head) minHeap.push(head);
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!minHeap.empty()) {
            ListNode* node = minHeap.top();
            minHeap.pop();

            if (node->next) minHeap.push(node->next);

            tail->next = node;
            tail = node;
        }

        tail->next = nullptr;
        return dummy.next;
    }
};