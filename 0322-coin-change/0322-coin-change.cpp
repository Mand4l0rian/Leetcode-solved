// 1: recursion
// class Solution {
// public:
// int solve(int ind, int amount, vector<int> coins){
//     if(amount==0) return 0;
//     if(ind==0){
//     if(amount % coins[0] == 0) return amount / coins[0];
//     return -1;
// }
//     int notpick=solve(ind-1,amount,coins);
//     int pick=-1;
//     if(amount>=coins[ind]) {
//         int sub = solve(ind, amount-coins[ind], coins);
//         if(sub != -1) pick = 1 + sub;
//     }
//     if(notpick==-1 && pick ==-1) return -1;
//     else if(notpick==-1) return pick;
//     else if(pick==-1) return notpick;
//     else return min(pick,notpick);
// }
//     int coinChange(vector<int>& coins, int amount) {
//         int n=coins.size();
//         return solve(n-1,amount,coins);
//     }
// };

// 2: recursion + memoization
// class Solution {
// public:
// int solve(int ind, int amount, vector<int> coins, vector<vector<int>>& dp){
//     if(dp[ind][amount]!=INT_MIN) return dp[ind][amount];
//     if(amount==0) return dp[ind][amount]=0;
//     if(ind==0){
//     if(amount % coins[0] == 0) return dp[ind][amount]=amount / coins[0];
//     return dp[ind][amount]=-1;
// }
//     int notpick=solve(ind-1,amount,coins,dp);
//     int pick=-1;
//     if(amount>=coins[ind]) {
//         int sub = solve(ind, amount-coins[ind], coins,dp);
//         if(sub != -1) pick = 1 + sub;
//     }
//     if(notpick==-1 && pick ==-1) return dp[ind][amount]=-1;
//     else if(notpick==-1) return dp[ind][amount]=pick;
//     else if(pick==-1) return dp[ind][amount]=notpick;
//     else return dp[ind][amount]=min(pick,notpick);
// }
//     int coinChange(vector<int>& coins, int amount) {
//         int n=coins.size();
//         vector<vector<int>> dp(n,vector<int>(amount+1,INT_MIN));
//         return solve(n-1,amount,coins,dp);
//     }
// };

// 3: tabulation
// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         int n=coins.size();
//         vector<vector<int>> dp(n,vector<int>(amount+1,0));
//         for(int j=1;j<=amount;j++){
//             if(j%coins[0]==0) dp[0][j]=j/coins[0];
//             else dp[0][j]=-1;
//         }
//         for(int i=1;i<n;i++){
//             for(int j=1;j<=amount;j++){
//                 int notpick=dp[i-1][j];
//                 int pick=-1;
//                 if(j>=coins[i]){
//                     int sub=dp[i][j-coins[i]];
//                     if(sub!=-1) pick=1+sub;
//                 }
//                 if(notpick==-1 && pick ==-1) dp[i][j]=-1;
//                 else if(notpick==-1) dp[i][j]=pick;
//                 else if(pick==-1) dp[i][j]=notpick;
//                 else dp[i][j]=min(pick,notpick);
//             }
//         }
//         return dp[n-1][amount];
//     }
// };

// 4: space optimization
// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         int n=coins.size();
//         vector<int> dp(amount+1,-1);
//         dp[0]=0;
//         for(int j=1;j<=amount;j++){
//             if(j%coins[0]==0) dp[j]=j/coins[0];
//         }
//         for(int i=1;i<n;i++){
//             for(int j=coins[i];j<=amount;j++){
//                 if(dp[j]==-1 && dp[j-coins[i]]==-1) dp[j]=-1;
//                 else if(dp[j]==-1) dp[j]=1+dp[j-coins[i]];
//                 else if(dp[j-coins[i]]==-1) dp[j]=dp[j];
//                 else dp[j]=min(dp[j-coins[i]]+1,dp[j]);
//             }
//         }
//         return dp[amount];
//     }
// };







// RECURSION:
// class Solution {
// public:
//     int solve(int ind, int amount, vector<int>& coins) {
//         if (amount == 0) return 0;
//         if (ind == coins.size()) return 1e9;
//         int take = 1e9;
//         if (coins[ind] <= amount) take = 1 + solve(ind, amount - coins[ind], coins);
//         int notTake = solve(ind + 1, amount, coins);
//         return min(take, notTake);
//     }
//     int coinChange(vector<int>& coins, int amount) {
//         int ans = solve(0, amount, coins);
//         return ans >= 1e9 ? -1 : ans;
//     }
// };

// MEMOIZATION:
class Solution {
public:
    int solve(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if (amount == 0) return 0;
        if (ind == coins.size()) return 1e9;
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int take = 1e9;
        if (coins[ind] <= amount) take = 1 + solve(ind,amount-coins[ind],coins,dp);
        int notTake = solve(ind+1,amount,coins,dp);
        return dp[ind][amount]=min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans = solve(0,amount,coins,dp);
        return ans >= 1e9 ? -1 : ans;
    }
};