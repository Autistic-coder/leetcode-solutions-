class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* prev = nullptr;
        TreeNode* curr = root;

        while (curr != nullptr) {
            if (curr->left != nullptr) {
                TreeNode* predecessor = curr->left;

                while (predecessor->right != nullptr &&
                       predecessor->right != curr) {
                    predecessor = predecessor->right;
                }

                if (predecessor->right == nullptr) {
                    predecessor->right = curr;
                    curr = curr->left;
                    continue;
                }

                predecessor->right = nullptr;
            }

            if (prev != nullptr && prev->val > curr->val) {
                if (first == nullptr)
                    first = prev;
                second = curr;
            }

            prev = curr;
            curr = curr->right;
        }

        if (first != nullptr && second != nullptr) {
            int temp = first->val;
            first->val = second->val;
            second->val = temp;
        }
    }
};