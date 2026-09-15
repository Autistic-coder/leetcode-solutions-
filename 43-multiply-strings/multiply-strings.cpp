#include <string>
#include <vector>

class Solution {
public:
    std::string multiply(std::string num1, std::string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        int n = num1.length();
        int m = num2.length();
        std::vector<int> res(n + m, 0);
        
        // Multiply each digit from right to left
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j, p2 = i + j + 1;
                int sum = mul + res[p2];
                
                res[p2] = sum % 10;
                res[p1] += sum / 10;
            }
        }
        
        // Convert vector to string, ignoring leading zeros
        std::string ans = "";
        for (int val : res) {
            if (!(ans.empty() && val == 0)) {
                ans.push_back(val + '0');
            }
        }
        
        return ans.empty() ? "0" : ans;
    }
};