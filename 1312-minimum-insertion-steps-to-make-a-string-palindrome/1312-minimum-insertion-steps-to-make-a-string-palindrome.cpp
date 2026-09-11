// 1: tabulation
// class Solution {
// public:
//     int minInsertions(string s) {
//         int n=s.length();
//         vector<vector<int>> dp(n+1,vector<int>(n+1,0));
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=n;j++){
//                 if(s[i-1]==s[n-j]) dp[i][j]=1+dp[i-1][j-1];
//                 else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//             }
//         }
//         return n-dp[n][n];
//     }
// };

// 2: space optimization
// class Solution {
// public:
//     int minInsertions(string s) {
//         int n=s.length();
//         vector<int> dp(n+1,0);
//         vector<int> temp(n+1,0);
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=n;j++){
//                 if(s[i-1]==s[n-j]) temp[j]=1+dp[j-1];
//                 else temp[j]=max(dp[j],temp[j-1]);
//             }
//             dp=temp;
//         }
//         return n-dp[n];
//     }
// };








// TABULATION:
// class Solution {
// public:
//     int minInsertions(string s) {
//         vector<vector<int>> dp(s.size()+1,vector<int>(s.size()+1,0));
//         for(int i=s.size()-1;i>=0;i--){
//             for(int j=s.size()-1;j>=0;j--){
//                 if(s[i]==s[s.size()-1-j]) dp[i][j]=1+dp[i+1][j+1];
//                 else{
//                     dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
//                 }
//             }
//         }
//         return s.size()-dp[0][0];
//     }
// };

// SPACE OPTIMIZATION:
class Solution {
public:
    int minInsertions(string s) {
        vector<int> dp(s.size()+1,0);
        vector<int> temp(s.size()+1,0);
        for(int i=s.size()-1;i>=0;i--){
            for(int j=s.size()-1;j>=0;j--){
                if(s[i]==s[s.size()-1-j]) temp[j]=1+dp[j+1];
                else{
                    temp[j]=max(dp[j],temp[j+1]);
                }
            }
            dp=temp;
        }
        return s.size()-dp[0];
    }
};