// 1: recursion
// class Solution {
// public:
// int solve(int ind, int prev, vector<int>& nums){
//     if(ind==nums.size()) return 0;
//     if(prev==-1) return max(1+solve(ind+1,ind,nums),solve(ind+1,prev,nums));
//     else{
//         int nottake=solve(ind+1,prev,nums);
//         int take=0;
//         if(nums[prev]<nums[ind]) take=1+solve(ind+1,ind,nums);
//         return max(take,nottake);
//     }

// }
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         return solve(0,-1,nums);
//     }
// };

// 2: memoization
// class Solution {
// public:
// int solve(int ind, int prev, vector<int>& nums, vector<vector<int>>& dp){
//     if(ind==nums.size()) return 0;
//     if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
//     if(prev==-1) return dp[ind][prev+1]=max(1+solve(ind+1,ind,nums,dp),solve(ind+1,prev,nums,dp));
//     else{
//         int nottake=solve(ind+1,prev,nums,dp);
//         int take=0;
//         if(nums[prev]<nums[ind]) take=1+solve(ind+1,ind,nums,dp);
//         return dp[ind][prev+1]=max(take,nottake);
//     }

// }
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<vector<int>> dp(n,vector<int>(n+1,-1));
//         return solve(0,-1,nums,dp);
//     }
// };

// 3: tabulation
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<vector<int>> dp(n+1,vector<int>(n+1,0));
//         for(int i=n-1;i>=0;i--){
//             for(int j=0;j<=i;j++){
//                 if(j==0){
//                     dp[i][j]=max(1+dp[i+1][i+1],dp[i+1][j]);
//                 }else{
//                     int take=0;
//                     if(nums[j-1]<nums[i]) take=1+dp[i+1][i+1];
//                     dp[i][j]=max(take,dp[i+1][j]);
//                 }
//             }
//         }
//         return dp[0][0];
//     }
// };

// 4: space optimization
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> dp(n+1,0);
//         for(int i=n-1;i>=0;i--){
//             for(int j=0;j<=i;j++){
//                 if(j==0){
//                     dp[j]=max(1+dp[i+1],dp[j]);
//                 }else{
//                     int take=0;
//                     if(nums[j-1]<nums[i]) take=1+dp[i+1];
//                     dp[j]=max(take,dp[j]);
//                 }
//             }
//         }
//         return dp[0];
//     }
// };

// 5: binary search tc= O(NlogN), doesnt use dp in solution, lower_bound inbuilt function
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {

//         vector<int> temp;
//         temp.push_back(nums[0]);

//         int len = 1;

//         for (int i = 1; i < nums.size(); i++) {

//             if (nums[i] > temp.back()) {
//                 temp.push_back(nums[i]);
//                 len++;
//             }
//             else {
//                 int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
//                 temp[ind] = nums[i];
//             }
//         }

//         return len;
//     }
// };















// RECURSION:
// class Solution {
// public:
//     int solve(int ind, int prev, vector<int>& nums){
//         if(ind==nums.size()) return 0;
//         int take=0;
//         if(prev==-1 || nums[ind]>nums[prev]){
//             take=1+solve(ind+1,ind,nums);
//         }
//         int nottake=solve(ind+1,prev,nums);
//         return max(take,nottake);
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         return solve(0,-1,nums);
//     }
// };

// MEMOIZATION:
// class Solution {
// public:
//     int solve(int ind, int prev, vector<int>& nums, vector<vector<int>>& dp){
//         if(ind==nums.size()) return 0;
//         if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
//         int take=0;
//         if(prev==-1 || nums[ind]>nums[prev]){
//             take=1+solve(ind+1,ind,nums,dp);
//         }
//         int nottake=solve(ind+1,prev,nums,dp);
//         return dp[ind][prev+1]=max(take,nottake);
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
//         return solve(0,-1,nums,dp);
//     }
// };

// TABULATION:
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,0));
//         for(int i=nums.size()-1;i>=0;i--){
//             for(int j=nums.size();j>=0;j--){
//                 int take=0;
//                 if(j==0 || nums[i]>nums[j-1]){
//                     take=1+dp[i+1][i+1];
//                 }
//                 int nottake=dp[i+1][j];
//                 dp[i][j]=max(take,nottake);
//             }
//         }
//         return dp[0][0];
//     }
// };

// SPACE OPTIMIZATION:
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         vector<int> dp(nums.size()+1,0);
//         for(int i=nums.size()-1;i>=0;i--){
//             for(int j=nums.size();j>=0;j--){
//                 int take=0;
//                 if(j==0 || nums[i]>nums[j-1]){
//                     take=1+dp[i+1];
//                 }
//                 int nottake=dp[j];
//                 dp[j]=max(take,nottake);
//             }
//         }
//         return dp[0];
//     }
// };

// BINARY SEARCH:
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);
        for(auto num: nums){
            if(num>temp.back()){
                temp.push_back(num);
            }else{
                int ind=lower_bound(temp.begin(),temp.end(),num)-temp.begin();
                temp[ind]=num;
            }
        }
        return temp.size();
    }
};