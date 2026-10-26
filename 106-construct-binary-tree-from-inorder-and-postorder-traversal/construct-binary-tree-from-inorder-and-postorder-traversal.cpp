
class Solution {
public:
    unordered_map<int, int> mp;
    int idx;

    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
                    int left, int right) {
        if (left > right)
            return nullptr;

        int val = postorder[idx--];
        TreeNode* root = new TreeNode(val);

        int mid = mp[val];

        root->right = build(inorder, postorder, mid + 1, right);
        root->left = build(inorder, postorder, left, mid - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        idx = n - 1;
        mp.clear();

        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }

        return build(inorder, postorder, 0, n - 1);
    }
};
