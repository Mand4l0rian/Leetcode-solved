// 1: Recursive solution
// class Solution {
// public:
// int solve(int m, int n, vector<vector<int>>& grid){
//     if(m<0 || n<0) return INT_MAX;
//     if(m==0 && n==0) return grid[m][n];
//     return grid[m][n]+min(solve(m-1,n,grid),solve(m,n-1,grid));
// }
//     int minPathSum(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         return solve(m-1,n-1,grid);
//     }
// };

// 2: Recursion+memoization
// class Solution {
// public:
// int solve(int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp){
//     if(m<0 || n<0) return INT_MAX;
//     if(m==0 && n==0) return dp[m][n]=grid[m][n];
//     if(dp[m][n]!=-1) return dp[m][n];
//     return dp[m][n]=grid[m][n]+min(solve(m-1,n,grid,dp),solve(m,n-1,grid,dp));
// }
//     int minPathSum(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         vector<vector<int>> dp(m,vector<int>(n,-1));
//         solve(m-1,n-1,grid,dp);
//         return dp[m-1][n-1];
//     }
// };

// 3: Tabulization
// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         vector<vector<int>> dp(m,vector<int>(n,-1));
//         for(int i=0; i<m; i++){
//             for(int j=0; j<n; j++){
//                 if(i==0 && j==0){
//                     dp[i][j]=grid[i][j];
//                 }else if(i==0){
//                     dp[i][j]=grid[i][j]+dp[i][j-1];
//                 }else if(j==0){
//                     dp[i][j]=grid[i][j]+dp[i-1][j];
//                 }else dp[i][j]=grid[i][j]+ min(dp[i-1][j],dp[i][j-1]);
//             }
//         }
//         return dp[m-1][n-1];
//     }
// };

// 4: space optimization
// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         vector<int> dp(n);
//         dp[0]=grid[0][0];
//         for(int i=1; i<n; i++){
//             dp[i]=dp[i-1]+grid[0][i];
//         }
//         for(int i=1; i<m; i++){
//             for(int j=0; j<n; j++){
//                 if(j==0){
//                     dp[j]=dp[j]+grid[i][j];
//                 }else{
//                     dp[j]=grid[i][j]+min(dp[j-1], dp[j]);
//                 }
//             }
//         }
//         return dp[n-1];
//     }
// };











// RECURSION:
// class Solution {
// public:
//     int solve(int i, int j, vector<vector<int>>& grid){
//         if(i==grid.size() || j==grid[0].size()) return INT_MAX;
//         if(i==grid.size()-1 && j==grid[0].size()-1) return grid[i][j];
//         int least= min(solve(i+1,j,grid),solve(i,j+1,grid));
//         if(least==INT_MAX) return INT_MAX; //safe case for when both down and right return INT_MAX
//         return grid[i][j]+least;
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         return solve(0,0,grid);
//     }
// };

// MEMOIZATION
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i==grid.size() || j==grid[0].size()) return INT_MAX;
        if(i==grid.size()-1 && j==grid[0].size()-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int least= min(solve(i+1,j,grid,dp),solve(i,j+1,grid,dp));
        return dp[i][j]=grid[i][j]+least;
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        return solve(0,0,grid,dp);
    }
};