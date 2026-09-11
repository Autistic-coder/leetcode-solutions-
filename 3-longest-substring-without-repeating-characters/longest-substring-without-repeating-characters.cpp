#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(256, -1);

        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.length(); right++) {
            unsigned char current = s[right];

            // Move left only if the character exists inside the current window
            if (lastIndex[current] >= left) {
                left = lastIndex[current] + 1;
            }

            lastIndex[current] = right;
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};