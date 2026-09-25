#include <vector>
using namespace std;

class Solution {
    void solve(int index, int target, vector<int>& candidates,
               vector<int>& current, vector<vector<int>>& answer) {
        
        if (target == 0) {
            answer.push_back(current);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] > target) {
                continue;
            }

            current.push_back(candidates[i]);
            solve(i, target - candidates[i], candidates, current, answer);
            current.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> current;

        solve(0, target, candidates, current, answer);

        return answer;
    }
};