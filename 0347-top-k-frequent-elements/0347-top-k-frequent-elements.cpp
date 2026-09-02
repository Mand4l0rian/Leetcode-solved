class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // 1. Count frequency
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // 2. Min heap: {frequency, element}
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        // 3. Keep only K most frequent elements
        for (auto& [num, count] : freq) {
            pq.push({count, num});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        // 4. Extract answer
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};