class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int ans = 0;

        for (int num : st) {
            // Start of a sequence
            if (!st.count(num - 1)) {
                int curr = num;
                int len = 1;

                while (st.count(curr + 1)) {
                    curr++;
                    len++;
                }

                ans = max(ans, len);
            }
        }

        return ans;
    }
};