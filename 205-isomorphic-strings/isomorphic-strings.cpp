#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> sToT(256, -1);
        vector<int> tToS(256, -1);

        for (int i = 0; i < s.length(); i++) {
            unsigned char first = s[i];
            unsigned char second = t[i];

            // Check both directions of mapping
            if (sToT[first] != -1 && sToT[first] != second) {
                return false;
            }

            if (tToS[second] != -1 && tToS[second] != first) {
                return false;
            }

            sToT[first] = second;
            tToS[second] = first;
        }

        return true;
    }
};