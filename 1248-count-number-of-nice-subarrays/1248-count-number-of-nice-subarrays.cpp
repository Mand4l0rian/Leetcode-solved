// PREFIX SUM: NOT SPACE OPTIMAL
// class Solution {
// public:
//     int numberOfSubarrays(vector<int>& nums, int k) {
//         unordered_map<int, int> mp;

//         // 0 odd numbers before the array
//         mp[0] = 1;

//         int oddCount = 0;
//         int ans = 0;

//         for (int num : nums) {
//             if (num % 2 == 1)
//                 oddCount++;

//             // Need previous prefix with:
//             // previousOddCount = oddCount - k
//             if (mp.count(oddCount - k))
//                 ans += mp[oddCount - k];

//             mp[oddCount]++;
//         }

//         return ans;
//     }
// };

// SLIDING WINDOW: OPTIMAL
class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        int left = 0;
        int odds = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {

            if (nums[right] % 2 == 1)
                odds++;

            while (odds > k) {
                if (nums[left] % 2 == 1)
                    odds--;

                left++;
            }

            ans += right - left + 1;
        }

        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};