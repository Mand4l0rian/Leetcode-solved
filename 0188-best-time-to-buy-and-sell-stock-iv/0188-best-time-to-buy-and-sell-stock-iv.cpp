// 1: recursive
// class Solution {
// public:
// int solve(int ind, bool buy, int trans, vector<int>& prices){
//     if(ind==prices.size()) return 0;
//     if(buy && trans==0) return 0;
//     if(buy){
//         return max(-prices[ind]+solve(ind+1,false,trans-1,prices),solve(ind+1,true,trans,prices));
//     }else{
//         return max(prices[ind]+solve(ind+1,true,trans,prices),solve(ind+1,false,trans,prices));
//     }
// }
//     int maxProfit(int k, vector<int>& prices) {
//         return solve(0,true,k,prices);
//     }
// };
// 2: memoization
// class Solution {
// public:
// int solve(int ind, bool buy, int trans, vector<int>& prices, vector<vector<vector<int>>>& dp){
//     if(ind==prices.size()) return 0;
//     if(buy && trans==0) return 0;
//     if(dp[ind][buy][trans]!=-1) return dp[ind][buy][trans];
//     if(buy){
//         return dp[ind][buy][trans]=max(-prices[ind]+solve(ind+1,false,trans-1,prices,dp),solve(ind+1,true,trans,prices,dp));
//     }else{
//         return dp[ind][buy][trans]=max(prices[ind]+solve(ind+1,true,trans,prices,dp),solve(ind+1,false,trans,prices,dp));
//     }
// }
//     int maxProfit(int k, vector<int>& prices) {
//         vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2, vector<int>(k+1, -1)));
//         return solve(0,true,k,prices,dp);
//     }
// };

// 3: tabulation
// class Solution {
// public:
//     int maxProfit(int k, vector<int>& prices) {
//         int n=prices.size();
//         vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2, vector<int>(k+1, 0)));
//         for(int i=n-1;i>=0;i--){
//             for(int j=0;j<=1;j++){
//                 for(int m=0;m<=k;m++){
//                 if(j==1 && m==0) continue;
//                 if(j){
//                     dp[i][j][m]=max(-prices[i]+dp[i+1][0][m-1],dp[i+1][1][m]);
//                 }else{
//                     dp[i][j][m]=max(prices[i]+dp[i+1][1][m],dp[i+1][0][m]);
//                 }
//                 }
//             }
//         }
//         return dp[0][1][k];
//     }
// };

// 4: space optimization
// class Solution {
// public:
//     int maxProfit(int k, vector<int>& prices) {
//         int n=prices.size();
//         vector<vector<int>> dp(2, vector<int>(k+1, 0));
//         vector<vector<int>> temp(2, vector<int>(k+1, 0));
//         for(int i=n-1;i>=0;i--){
//             for(int j=0;j<=1;j++){
//                 for(int m=0;m<=k;m++){
//                 if(j==1 && m==0) continue;
//                 if(j){
//                     temp[j][m]=max(-prices[i]+dp[0][m-1],dp[1][m]);
//                 }else{
//                     temp[j][m]=max(prices[i]+dp[1][m],dp[0][m]);
//                 }
//                 }
//             }
//             dp=temp;
//         }
//         return dp[1][k];
//     }
// };









// RECURSION:
// class Solution {
// public:
//     int solve(int ind, bool canbuy, int k, vector<int>& prices){
//         if(ind==prices.size() || k==0) return 0;
//         if(canbuy){
//             return max(-prices[ind]+solve(ind+1,!canbuy,k,prices),solve(ind+1,canbuy,k,prices));
//         }else{
//             return max(prices[ind]+solve(ind,!canbuy,k-1,prices),solve(ind+1,canbuy,k,prices));
//         }
//     }
//     int maxProfit(int k, vector<int>& prices) {
//         return solve(0,true,k,prices);
//     }
// };

// MEMOIZATION:
// class Solution {
// public:
//     int solve(int ind, int canbuy, int k, vector<int>& prices, vector<vector<vector<int>>>& dp){
//         if(ind==prices.size() || k==0) return 0;
//         if(dp[ind][canbuy][k]!=-1) return dp[ind][canbuy][k];
//         if(canbuy){
//             return dp[ind][canbuy][k]=max(-prices[ind]+solve(ind+1,!canbuy,k,prices,dp),solve(ind+1,canbuy,k,prices,dp));
//         }else{
//             return dp[ind][canbuy][k]=max(prices[ind]+solve(ind,!canbuy,k-1,prices,dp),solve(ind+1,canbuy,k,prices,dp));
//         }
//     }
//     int maxProfit(int k, vector<int>& prices) {
//         vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));
//         return solve(0,1,k,prices,dp);
//     }
// };

// TABULATION:
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        for(int i=prices.size()-1;i>=0;i--){
            for(int j=1;j>=0;j--){
                for(int n=1;n<=k;n++){
                    if(j){
                        dp[i][j][n]=max(-prices[i]+dp[i+1][0][n],dp[i+1][1][n]);
                    }else{
                        dp[i][j][n]=max(prices[i]+dp[i][1][n-1],dp[i+1][0][n]);
                    }
                }
            }
        }
        return dp[0][1][k];
    }
};