#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> mapping = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> result = {""};

        for (char digit : digits) {
            vector<string> next;

            for (const string& combination : result) {
                for (char letter : mapping[digit - '0']) {
                    next.push_back(combination + letter);
                }
            }

            result = move(next);
        }

        return result;
    }
};