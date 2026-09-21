class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;

        for (int i = 0; i < nums.size(); i++) {
            // If we can't reach this index, we're stuck
            if (i > farthest)
                return false;

            // Update the farthest position we can reach
            farthest = max(farthest, i + nums[i]);

            
        }

        return true;
    }
};