class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;

        for (const auto& description : descriptions) {
            int parent = description[0];
            int child = description[1];
            int isLeft = description[2];

            if (nodes.find(parent) == nodes.end()) {
                nodes[parent] = new TreeNode(parent);
            }

            if (nodes.find(child) == nodes.end()) {
                nodes[child] = new TreeNode(child);
            }

            if (isLeft == 1) {
                nodes[parent]->left = nodes[child];
            } else {
                nodes[parent]->right = nodes[child];
            }

            children.insert(child);
        }

        for (const auto& entry : nodes) {
            if (children.find(entry.first) == children.end()) {
                return entry.second;
            }
        }

        return nullptr;
    }
};