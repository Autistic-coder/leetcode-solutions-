#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result;

        while (columnNumber > 0) {
            columnNumber--;  // Convert from 1-based to 0-based

            char letter = 'A' + (columnNumber % 26);
            result.push_back(letter);

            columnNumber /= 26;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};