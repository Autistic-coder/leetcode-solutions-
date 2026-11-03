class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        auto bounds = minmax_element(nums.begin(), nums.end());
        long long difference = 1LL * (*bounds.second) - (*bounds.first);
        return difference * k;
    }
};