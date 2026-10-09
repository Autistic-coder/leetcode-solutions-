class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> frequency(26, 0);
        vector<bool> used(26, false);
        string result;

        for (char ch : s) {
            frequency[ch - 'a']++;
        }

        for (char ch : s) {
            int index = ch - 'a';
            frequency[index]--;

            if (used[index]) {
                continue;
            }

            while (!result.empty() &&
                   result.back() > ch &&
                   frequency[result.back() - 'a'] > 0) {
                used[result.back() - 'a'] = false;
                result.pop_back();
            }

            result.push_back(ch);
            used[index] = true;
        }

        return result;
    }
};