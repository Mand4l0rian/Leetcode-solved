class Solution {
public:
    vector<vector<string>> ans;
    bool ispalindrome(int i, int j, string& s) {
        int flag = true;
        while (i < j) {
            if (s[i] != s[j]) {
                flag = false;
                break;
            }
            i++;
            j--;
        }
        return flag;
    }
    void solve(int i, int j, string& s, vector<string>& temp) {
        if(j==s.length()){
            if(i==j) ans.push_back(temp);
            return;
        }
        if (ispalindrome(i, j, s)) {
            temp.push_back(s.substr(i, j-i+1));
            solve(j + 1, j + 1, s, temp);
            temp.pop_back();
        }
        solve(i, j + 1, s, temp);
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        solve(0,0,s,temp);
        return ans;
    }
};