class Solution {
public:
    vector<vector<int>> ans;
    void solve(int start, int sum, int target, vector<int>& candidates, vector<int>& temp){
        if(sum>target) return;
        if(sum==target){
            ans.push_back(temp);
        }
        for(int i=start;i<candidates.size();i++){
            if(i>start && candidates[i]==candidates[i-1]) continue;
            temp.push_back(candidates[i]);
            solve(i+1,sum+candidates[i],target,candidates,temp);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        solve(0,0,target,candidates,temp);
        return ans;
    }
};