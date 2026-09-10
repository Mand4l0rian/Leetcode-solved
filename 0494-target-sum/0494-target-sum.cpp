// 1: recursion
// class Solution {
// public:
// int solve(int ind, int target, vector<int> nums){
//     if(ind==0) return (target+nums[0]==0)+(target-nums[0]==0);
//     int plus=solve(ind-1,target+nums[ind],nums);
//     int minus=solve(ind-1,target-nums[ind],nums);
//     return plus+minus;
// }
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int n=nums.size();
//         return solve(n-1,target,nums);
//     }
// };

// 2: recursion+ memoization
// class Solution {
// public:
// int solve(int ind, int target, vector<int> nums, vector<vector<int>>& dp, int zeroind){
//     if(dp[ind][abs(zeroind-target)]!=-1) return dp[ind][abs(zeroind-target)];
//     if(ind==0) return dp[ind][abs(zeroind-target)]=(target+nums[0]==0)+(target-nums[0]==0);
//     int plus=solve(ind-1,target+nums[ind],nums,dp,zeroind);
//     int minus=solve(ind-1,target-nums[ind],nums,dp,zeroind);
//     return dp[ind][abs(zeroind-target)]=plus+minus;
// }
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int n=nums.size();
//         int totalsum=accumulate(nums.begin(),nums.end(),0);
//         int newtarget=2*totalsum+1;
//         int zeroind=target-totalsum;
//         vector<vector<int>> dp(n,vector<int>(newtarget,-1));
//         return solve(n-1,target,nums,dp,zeroind);
//     }
// };

// 3: tabulation
// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int n=nums.size();
//         int totalsum=accumulate(nums.begin(),nums.end(),0);
//         int newtarget=2*totalsum+1;
//         int zeroind=target-totalsum;
//         int lastind=target+totalsum;
//         vector<vector<int>> dp(n,vector<int>(newtarget,0));
//         for(int j=0; j<=newtarget-1;j++){
//             dp[0][j]=(j+zeroind+nums[0]==0)+(j+zeroind-nums[0]==0);
//         }
//         for(int i=1;i<n;i++){
//             for(int j=0;j<=newtarget-1;j++){
//                 int ways=0;
//                 if(j+nums[i]<=newtarget-1) ways=ways+dp[i-1][j+nums[i]];
//                 if(j-nums[i]>=0) ways=ways+dp[i-1][j-nums[i]];
//                 dp[i][j]=ways;
//             }
//         }
//         return dp[n-1][abs(zeroind-target)];
//     }
// };

// 4: space optimization
// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int n=nums.size();
//         int totalsum=accumulate(nums.begin(),nums.end(),0);
//         int newtarget=2*totalsum+1;
//         int zeroind=target-totalsum;
//         int lastind=target+totalsum;
//         vector<int> dp(newtarget,0);
//         vector<int> temp(newtarget);
//         for(int j=0; j<=newtarget-1;j++){
//             dp[j]=(j+zeroind+nums[0]==0)+(j+zeroind-nums[0]==0);
//         }
//         for(int i=1;i<n;i++){
//             for(int j=0;j<=newtarget-1;j++){
//                 int ways=0;
//                 if(j+nums[i]<=newtarget-1) ways=ways+dp[j+nums[i]];
//                 if(j-nums[i]>=0) ways=ways+dp[j-nums[i]];
//                 temp[j]=ways;
//             }
//             dp=temp;
//         }
//         return dp[abs(zeroind-target)];
//     }
// };


















// RECURSION:
class Solution {
public:
    int solve(int ind, int target, vector<int>& nums){
        if(ind==nums.size()){
            if(target==0) return 1;
            else return 0;
        }
        int add=solve(ind+1,target+nums[ind],nums);
        int sub=solve(ind+1,target-nums[ind],nums);
        return add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0,target,nums);
    }
};