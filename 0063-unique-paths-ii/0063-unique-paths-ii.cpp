class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<int> dp(n, 0);

        dp[0] = (obstacleGrid[0][0] == 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                }
                else if (j > 0) {
                    dp[j] += dp[j - 1];
                }
            }
        }

        return dp[n - 1];
    }
};

// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m=obstacleGrid.size();
//         int n=obstacleGrid[0].size();
//         vector<int> dp(n+1,0);
//         for(int i=m-1;i>=0;i--){
//             for(int j=n-1;j>=0;j--){
//                 if(obstacleGrid[i][j]==1){
//                     dp[j]=0;
//                     continue;
//                 }
//                 if(i==m-1 && j==n-1) dp[j]=1;
//                 else dp[j]=dp[j]+dp[j+1];
//             }
//         }
//         return dp[0];
//     }
// };