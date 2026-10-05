class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;

        stack<TreeNode*> nodes;
        nodes.push(root);

        while (!nodes.empty()) {
            TreeNode* node = nodes.top();
            nodes.pop();

            result.push_back(node->val);

            if (node->left) nodes.push(node->left);
            if (node->right) nodes.push(node->right);
        }

        reverse(result.begin(), result.end());
        return result;
    }
};