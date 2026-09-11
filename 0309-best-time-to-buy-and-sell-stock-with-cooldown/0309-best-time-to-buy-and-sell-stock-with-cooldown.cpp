// 1: recursion
// class Solution {
// public:
// int solve(int ind, bool buy, vector<int>& prices){
//     if(ind>=prices.size()) return 0;
//     if(buy){
//         return max(-prices[ind]+solve(ind+1, 0,prices),solve(ind+1,1,prices));
//     }else{
//         return max(prices[ind]+solve(ind+2,1,prices),solve(ind+1,0,prices));
//     }
// }
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         return solve(0,1,prices);
//     }
// };

// 2: memoization
// class Solution {
// public:
// int solve(int ind, bool buy, vector<int>& prices, vector<vector<int>>& dp){
//     if(ind>=prices.size()) return 0;
//     if(dp[ind][buy]!=-1) return dp[ind][buy];
//     if(buy){
//         return dp[ind][buy]=max(-prices[ind]+solve(ind+1, 0,prices,dp),solve(ind+1,1,prices,dp));
//     }else{
//         return dp[ind][buy]=max(prices[ind]+solve(ind+2,1,prices,dp),solve(ind+1,0,prices,dp));
//     }
// }
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         vector<vector<int>> dp(n,vector<int>(2,-1));
//         return solve(0,1,prices,dp);
//     }
// };

// 3: tabulation
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         vector<vector<int>> dp(n+2,vector<int>(2,0));
//         for(int i=n-1;i>=0;i--){
//             for(int j=0;j<=1;j++){
//                 if(j){
//                     dp[i][j]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
//                 }else{
//                     dp[i][j]=max(prices[i]+dp[i+2][1],dp[i+1][0]);
//                 }
//             }
//         }
//         return dp[0][1];
//     }
// };

// 4: space optimization
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         vector<int> dp(2,0);
//         vector<int> temp1(2,0);
//         vector<int> temp2(2,0);
//         for(int i=n-1;i>=0;i--){
//             for(int j=0;j<=1;j++){
//                 if(j){
//                     dp[j]=max(-prices[i]+temp1[0],temp1[1]);
//                 }else{
//                     dp[j]=max(prices[i]+temp2[1],temp1[0]);
//                 }
//             }
//             temp2=temp1;
//             temp1=dp;
//         }
//         return dp[1];
//     }
// };












// RECURSION:
// class Solution {
// public:
//     int solve(int ind, bool canbuy, vector<int>& prices){
//         if(ind>=prices.size()) return 0;
//         if(canbuy){
//             return max(-prices[ind]+solve(ind+1,!canbuy,prices),solve(ind+1,canbuy,prices));
//         }else{
//             return max(prices[ind]+solve(ind+2,!canbuy,prices),solve(ind+1,canbuy,prices));
//         }
//     }
//     int maxProfit(vector<int>& prices) {
//         return solve(0,true,prices);
//     }
// };

// MEMOIZATION:
class Solution {
public:
    int solve(int ind, int canbuy, vector<int>& prices, vector<vector<int>>& dp){
        if(ind>=prices.size()) return 0;
        if(dp[ind][canbuy]!=-1) return dp[ind][canbuy];
        if(canbuy){
            return dp[ind][canbuy]=max(-prices[ind]+solve(ind+1,!canbuy,prices,dp),solve(ind+1,canbuy,prices,dp));
        }else{
            return dp[ind][canbuy]=max(prices[ind]+solve(ind+2,!canbuy,prices,dp),solve(ind+1,canbuy,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return solve(0,true,prices,dp);
    }
};