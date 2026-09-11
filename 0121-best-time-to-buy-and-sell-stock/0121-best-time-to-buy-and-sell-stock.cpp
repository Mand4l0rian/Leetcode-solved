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
class Solution {
public:
    int solve(int ind, bool canbuy, vector<int>& prices, vector<vector<int>>& dp){
        if(ind==prices.size()) return 0;
        if(dp[ind][canbuy]!=-1) return dp[ind][canbuy];
        if(canbuy){
            return dp[ind][canbuy]=max(-prices[ind]+solve(ind+1,!canbuy,prices,dp),solve(ind+1,canbuy,prices,dp));
        }else{
            return dp[ind][canbuy]=max(prices[ind],solve(ind+1,canbuy,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};