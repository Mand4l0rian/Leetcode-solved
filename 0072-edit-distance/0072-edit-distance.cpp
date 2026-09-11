// USING LCS: PASSES 1122/1149 TESTCASES. (SELF MADE SOLUTION)
// class Solution {
// public:
//     int minDistance(string word1, string word2) {
//         vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1,0));
//         for(int i=word1.size()-1;i>=0;i--){
//             for(int j=word2.size()-1;j>=0;j--){
//                 if(word1[i]==word2[j]) dp[i][j]=1+dp[i+1][j+1];
//                 else dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
//             }
//         }
//         int i=0;
//         int j=0;
//         int count=0;
//         while(i!=word1.size() && j!=word2.size()){
//             if(word1[i]==word2[j]){
//                 i++;
//                 j++;
//             }
//             else if(dp[i+1][j]==dp[i][j+1]){
//                 count++; // update operation
//                 i++;
//                 j++;
//             }else if(dp[i+1][j]>dp[i][j+1]){
//                 count++; // delete operation
//                 i++;
//             }else{
//                 count++; //insert operation
//                 j++;
//             }
//         }
//         while(i!=word1.size()){
//             count++; // extra remaining from word1 to be deleted
//             i++;
//         }
//         while(j!=word2.size()){
//             count++; // extra remaining in word2 at the end which need to be inserted in word1
//             j++;
//         }
//         return count;
//     }
// };


// RECURSION: REMEMBER THAT EVERYWHERE IN LCS PATTERN WHEN WE PERFORM RECURSION, WE DIRECTLY RETURN IN THE "TAKE" CASE WHICH IS CHARACTER MATCHING IN BOTH THE STRINGS, UNLIKE THE TRADITIONAL TAKE/NOTTAKE WHERE WE HAVE TO COMPARE TAKE AND NOTTAKE OUTPUTS IN THE FINAL RETURN STATEMENT OF THE FUNCTION.
class Solution {
public:
    int solve(int ind1, int ind2, string& s1, string& s2, vector<vector<int>>& dp){
        if(ind1==s1.size()) return s2.size()-ind2;
        if(ind2==s2.size()) return s1.size()-ind1;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(s1[ind1]==s2[ind2]) return dp[ind1][ind2]=solve(ind1+1,ind2+1,s1,s2,dp);
        return dp[ind1][ind2]=1+min({solve(ind1+1,ind2,s1,s2,dp),solve(ind1+1,ind2+1,s1,s2,dp),solve(ind1,ind2+1,s1,s2,dp)});
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        return solve(0,0,word1,word2,dp);
    }
};