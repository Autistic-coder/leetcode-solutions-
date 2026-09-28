#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int depth = 0, answer = 0;

        for (char c : s) {
            if (c == '(') {
                ++depth;
                answer = max(answer, depth);
            } else if (c == ')') {
                --depth;
            }
        }

        return answer;
    }
};