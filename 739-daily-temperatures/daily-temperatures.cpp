#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> pending;

        for (int i = 0; i < n; ++i) {
            while (!pending.empty() &&
                   temperatures[i] > temperatures[pending.top()]) {
                int day = pending.top();
                pending.pop();
                answer[day] = i - day;
            }
            pending.push(i);
        }

        return answer;
    }
};