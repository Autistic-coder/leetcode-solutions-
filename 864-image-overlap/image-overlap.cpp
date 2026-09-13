#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1,
                       vector<vector<int>>& img2) {
        vector<pair<int, int>> ones1;
        vector<pair<int, int>> ones2;

        int n = img1.size();

        // Store positions containing 1 in both images
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (img1[row][col] == 1) {
                    ones1.push_back({row, col});
                }

                if (img2[row][col] == 1) {
                    ones2.push_back({row, col});
                }
            }
        }

        unordered_map<int, int> translationCount;
        int maximumOverlap = 0;

        /*
         * For every pair of 1-bits, calculate the translation
         * required to move the img1 bit onto the img2 bit.
         */
        for (const auto& point1 : ones1) {
            for (const auto& point2 : ones2) {
                int rowShift = point2.first - point1.first;
                int colShift = point2.second - point1.second;

                // Convert the pair of shifts into one unique integer
                int key = (rowShift + n) * (2 * n) + (colShift + n);

                translationCount[key]++;
                maximumOverlap =
                    max(maximumOverlap, translationCount[key]);
            }
        }

        return maximumOverlap;
    }
};