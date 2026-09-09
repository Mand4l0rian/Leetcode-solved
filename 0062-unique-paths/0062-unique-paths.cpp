// 1st solution: Basic Recursion TC=O(2^(m+n)) branching factor^max depth of tree SC=O(m+n) because max size of recursive stack space =m+n= max depth of the tree  (reject due to tle).
// class Solution {
// public:
// int solve(int m, int n, int rows, int cols){
//     if(m==0 && n==0) return 1;
//     if(m<0 || n<0) return 0;
//     return solve(m-1,n,rows,cols)+solve(m,n-1,rows,cols);
// }
//     int uniquePaths(int m, int n) {
//         return solve(m-1,n-1,m,n);
//     }
// };

// 2nd solution: Recursion+ Memoization TC=O(m*n) computing for every node only once SC=O(m*n) for dp matrix and O(m+n) due to recursive stack space (accepted).
// class Solution {
// public:
// int solve(int m, int n, int rows, int cols, vector<vector<int>>& dp){
//     if(m==0 && n==0) return 1;
//     if(m<0 || n<0) return 0;
//     if(dp[m][n]!=-1) return dp[m][n];
//     else return dp[m][n]=solve(m-1,n,rows,cols,dp)+solve(m,n-1,rows,cols,dp);
// }
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m,vector<int>(n,-1));
//         return solve(m-1,n-1,m,n,dp);
//     }
// };

// 3rd solution: used tabulization TC=O(m*n) SC=(m*n)
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m,vector<int>(n));
//         dp[0][0]=1;
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(i==0 && j==0) continue;
//                 if(i==0){
//                     dp[i][j]=dp[i][j-1];
//                 }
//                 else if(j==0){
//                     dp[i][j]=dp[i-1][j];
//                 }
//                 else dp[i][j]=dp[i-1][j]+dp[i][j-1];
//             }
//         }
//         return dp[m-1][n-1];
//     }
// };

// 4th solution: Space Optimization of tabulization 2D->1D. TC=O(m*n) SC=O(n). BEST SOLUTION!!
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         vector<int> dp(n, 1);

//         for (int i = 1; i < m; i++) {
//             for (int j = 1; j < n; j++) {
//                 dp[j] = dp[j] + dp[j - 1];
//             }
//         }

//         return dp[n - 1];
//     }
// };


















// RECURSION:
// class Solution {
// public:
//     int solve(int i, int j, int& m, int& n){
//         if(i==m || j==n) return 0;
//         if(i==m-1 && j==n-1) return 1;
//         int down=solve(i+1,j,m,n);
//         int right=solve(i,j+1,m,n);
//         return down+right;
//     }
//     int uniquePaths(int m, int n) {
//         return solve(0,0,m,n);
//     }
// };

// MEMOIZATION:
// class Solution {
// public:
//     int solve(int i, int j, int& m, int& n, vector<vector<int>>& dp){
//         if(i==m || j==n) return 0;
//         if(i==m-1 && j==n-1) return 1;
//         if(dp[i][j]!=-1) return dp[i][j];
//         int down=solve(i+1,j,m,n,dp);
//         int right=solve(i,j+1,m,n,dp);
//         return dp[i][j]=down+right;
//     }
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m,vector<int>(n,-1));
//         return solve(0,0,m,n,dp);
//     }
// };

// TABULATION:
class Solution {
public:
    int solve(int i, int j, int& m, int& n, vector<vector<int>>& dp){
        if(i==m || j==n) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int down=solve(i+1,j,m,n,dp);
        int right=solve(i,j+1,m,n,dp);
        return dp[i][j]=down+right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[m-1][n-1]=1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1) continue;
                dp[i][j]=dp[i+1][j]+dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};