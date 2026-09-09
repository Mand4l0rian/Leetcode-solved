// RECURSION:
// class Solution {
// public:
//     int solve(int ind, int& end, vector<int>& nums){
//         if(ind>=end) return 0;
//         int take= nums[ind]+ solve(ind+2,end,nums);
//         int nottake= solve(ind+1,end,nums);
//         return max(take,nottake);
//     }
//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         int n1=n-1;
//         if(n==1) return nums[0];
//         return max(solve(0,n1,nums), solve(1,n,nums));
//     }
// };

// MEMOIZATION:
// class Solution {
// public:
//     int solve(int ind, int& end, vector<int>& nums, vector<int>& dp){
//         if(ind>=end) return 0;
//         if(dp[ind]!=-1) return dp[ind];
//         int take= nums[ind]+ solve(ind+2,end,nums,dp);
//         int nottake= solve(ind+1,end,nums,dp);
//         return dp[ind]=max(take,nottake);
//     }
//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         int n1=n-1;
//         if(n==1) return nums[0];
//         vector<int> dp(n,-1);
//         vector<int> dp1(n1,-1);
//         solve(0,n1,nums,dp1);
//         solve(1,n,nums,dp);
//         return max(dp1[0],dp[1]);
//     }
// };

// TABULATION:
class Solution {
public:
    int solve(int ind, int& end, vector<int>& nums, vector<int>& dp){
        if(ind>=end) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int take= nums[ind]+ solve(ind+2,end,nums,dp);
        int nottake= solve(ind+1,end,nums,dp);
        return dp[ind]=max(take,nottake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n+2,0);
        vector<int> dp1(n+1,0);
        for(int i=n-1;i>=0;i--){
            if(i!=n-1){
                int take1=nums[i]+dp1[i+2];
                int nottake1=dp1[i+1];
                dp1[i]=max(take1,nottake1);
            }
            if(i!=0){
                int take= nums[i]+dp[i+2];
                int nottake=dp[i+1];
                dp[i]=max(take,nottake);
            }
        }
        return max(dp1[0],dp[1]);
    }
};