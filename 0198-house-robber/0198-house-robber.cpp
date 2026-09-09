// RECURSION:
// class Solution {
// public:
//     int solve(int ind, vector<int>& nums){
//         if(ind>=nums.size()) return 0;
//         int take= nums[ind]+ solve(ind+2, nums);
//         int nottake= solve(ind+1,nums);
//         return max(take,nottake);
//     }
//     int rob(vector<int>& nums) {
//         return solve(0,nums);
//     }
// };

// MEMOIZATION:
// class Solution {
// public:
//     int solve(int ind, vector<int>& nums, vector<int>& dp){
//         if(ind>=nums.size()) return 0;
//         if(dp[ind]!=-1) return dp[ind];
//         int take= nums[ind]+ solve(ind+2,nums,dp);
//         int nottake= solve(ind+1,nums,dp);
//         return dp[ind]=max(take,nottake);
//     }
//     int rob(vector<int>& nums) {
//         vector<int> dp(nums.size(),-1);
//         solve(0,nums,dp);
//         return dp[0];
//     }
// };

// TABULATION:
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+2,0);
        for(int i=nums.size()-1;i>=0;i--){
            dp[i]=max(dp[i+1], nums[i]+dp[i+2]);
        }
        return dp[0];
    }
};