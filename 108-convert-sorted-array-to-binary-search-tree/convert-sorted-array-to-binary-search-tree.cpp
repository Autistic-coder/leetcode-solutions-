class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* buildTree(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        // Choose the middle element as the root
        int middle = left + (right - left) / 2;

        TreeNode* root = new TreeNode(nums[middle]);

        // Build the left and right subtrees
        root->left = buildTree(nums, left, middle - 1);
        root->right = buildTree(nums, middle + 1, right);

        return root;
    }
};