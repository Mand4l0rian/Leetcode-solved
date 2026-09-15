class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        // 0 odd numbers before the array
        mp[0] = 1;

        int oddCount = 0;
        int ans = 0;

        for (int num : nums) {
            if (num % 2 == 1)
                oddCount++;

            // Need previous prefix with:
            // previousOddCount = oddCount - k
            if (mp.count(oddCount - k))
                ans += mp[oddCount - k];

            mp[oddCount]++;
        }

        return ans;
    }
};