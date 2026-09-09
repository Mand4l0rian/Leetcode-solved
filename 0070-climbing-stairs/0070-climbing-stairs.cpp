// RECURSION:
// class Solution {
// public:
//     int climbStairs(int n) {
//         if(n==0) return 1;
//         else if(n<0) return 0;
//         return climbStairs(n-1)+climbStairs(n-2);
//     }
// };

//
class Solution {
public:
    int solve(int n, vector<int>& dp) {
        if(n<0) return 0;
        if(n==0) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=solve(n-1,dp)+solve(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        solve(n,dp);
        return dp[n];
    }
};