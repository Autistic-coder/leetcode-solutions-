#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        // Convert word1 prefix into an empty string using deletions
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }

        // Convert an empty string into word2 prefix using insertions
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    // Matching characters require no operation
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    int insertCharacter = dp[i][j - 1];
                    int deleteCharacter = dp[i - 1][j];
                    int replaceCharacter = dp[i - 1][j - 1];

                    dp[i][j] = 1 + min({
                        insertCharacter,
                        deleteCharacter,
                        replaceCharacter
                    });
                }
            }
        }

        return dp[m][n];
    }
};