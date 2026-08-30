class Solution {
public:
    vector<string> func(vector<pair<int,int>>& temp, int& n){
        vector<string> ans1;
        for(auto it: temp){
            string ans2(n,'.');
            int col=it.second;
            ans2[col]='Q';
            ans1.push_back(ans2);
        }
        return ans1;
    }
    vector<vector<string>> ans;
    void solve(int ind, int& n, vector<pair<int,int>>& temp){
        if(ind==n){
            ans.push_back(func(temp,n));
            return;
        }
        for(int i=0;i<n;i++){
            bool flag=true;
            for(auto it: temp){
                int row=it.first;
                int col=it.second;
                if(i==col || abs(row-ind)==abs(col-i)){
                    flag=false;
                    break;
                }
            }
            if(flag){
                temp.push_back({ind,i});
                solve(ind+1,n,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<pair<int,int>> temp;
        solve(0,n,temp);
        return ans;
    }
};