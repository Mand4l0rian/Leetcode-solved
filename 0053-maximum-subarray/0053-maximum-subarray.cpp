// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int currSum = nums[0];
//         int maxSum = nums[0];

//         for (int i = 1; i < nums.size(); i++) {
//             currSum = max(nums[i], currSum + nums[i]);
//             maxSum = max(maxSum, currSum);
//         }

//         return maxSum;
//     }
// };

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum=0;
        int maxsum=INT_MIN;
        for(int i=0;i<nums.size();i++){
            currsum+=nums[i];
            if(currsum>maxsum){
                maxsum=currsum;
            }
            if(currsum<0) currsum=0;
        }
        return maxsum;
    }
};