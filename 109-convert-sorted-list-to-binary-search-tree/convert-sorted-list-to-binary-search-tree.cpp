
class Solution {
public:
    TreeNode* build(ListNode*& head, int left, int right) {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;

        TreeNode* leftSubtree = build(head, left, mid - 1);

        TreeNode* root = new TreeNode(head->val);
        head = head->next;

        root->left = leftSubtree;
        root->right = build(head, mid + 1, right);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int n = 0;
        ListNode* temp = head;

        while (temp) {
            n++;
            temp = temp->next;
        }

        return build(head, 0, n - 1);
    }
};
