class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> frequency;

        // Count the frequency of every character
        for (char ch : s) {
            frequency[ch]++;
        }

        // Max heap: {frequency, character}
        priority_queue<pair<int, char>> maxHeap;

        for (auto entry : frequency) {
            maxHeap.push({entry.second, entry.first});
        }

        string result;

        // Add characters in decreasing frequency order
        while (!maxHeap.empty()) {
            int count = maxHeap.top().first;
            char ch = maxHeap.top().second;
            maxHeap.pop();

            while (count > 0) {
                result += ch;
                count--;
            }
        }

        return result;
    }
};