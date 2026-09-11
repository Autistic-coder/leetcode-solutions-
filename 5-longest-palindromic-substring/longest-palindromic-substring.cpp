#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int maxLength = 1;

        for (int i = 0; i < s.length(); i++) {
            // Odd-length palindrome: "aba"
            expand(s, i, i, start, maxLength);

            // Even-length palindrome: "abba"
            expand(s, i, i + 1, start, maxLength);
        }

        return s.substr(start, maxLength);
    }

private:
    void expand(const string& s, int left, int right,
                int& start, int& maxLength) {

        while (left >= 0 && right < s.length() &&
               s[left] == s[right]) {
            left--;
            right++;
        }

        int currentLength = right - left - 1;

        if (currentLength > maxLength) {
            maxLength = currentLength;
            start = left + 1;
        }
    }
};