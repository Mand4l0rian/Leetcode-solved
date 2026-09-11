// RECURSION:
// class Solution {
// public:
//     int solve(int ind, bool canbuy, vector<int>& prices){
//         if(ind==prices.size()) return 0;
//         if(canbuy){
//             return max(-prices[ind]+solve(ind+1,!canbuy,prices),solve(ind+1,canbuy,prices));
//         }else{
//             return max(prices[ind],solve(ind+1,canbuy,prices));
//         }
//     }
//     int maxProfit(vector<int>& prices) {
//         return solve(0,1,prices);
//     }
// };

// MEMOIZATION:
// class Solution {
// public:
//     int solve(int ind, bool canbuy, vector<int>& prices, vector<vector<int>>& dp){
//         if(ind==prices.size()) return 0;
//         if(dp[ind][canbuy]!=-1) return dp[ind][canbuy];
//         if(canbuy){
//             return dp[ind][canbuy]=max(-prices[ind]+solve(ind+1,!canbuy,prices,dp),solve(ind+1,canbuy,prices,dp));
//         }else{
//             return dp[ind][canbuy]=max(prices[ind],solve(ind+1,canbuy,prices,dp));
//         }
//     }
//     int maxProfit(vector<int>& prices) {
//         vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
//         return solve(0,1,prices,dp);
//     }
// };

// TABULATION:
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));
        for(int i=prices.size()-1;i>=0;i--){
            for(int j=1;j>=0;j--){
                if(j==1){
                    dp[i][j]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }else{
                    dp[i][j]=max(prices[i],dp[i+1][j]);
                }
            }
        }
        return dp[0][1];
    }
};