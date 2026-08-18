class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> freq;

        // Count frequency
        for(char c : s) {
            freq[c]++;
        }

        // Max heap: {frequency, character}
        priority_queue<pair<int, char>> pq;

        for(auto it : freq) {
            pq.push({it.second, it.first});
        }

        string ans;

        // Build answer
        while(!pq.empty()) {

            int count = pq.top().first;
            char ch = pq.top().second;

            pq.pop();

            ans += string(count, ch);
        }

        return ans;
    }
};