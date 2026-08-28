class Solution {
public:
    vector<vector<int>> ans;
    void solve(int ind, int sum, int target, vector<int>& candidates, vector<int>& temp){
        if(ind==candidates.size()) return;
        if(sum==target){
            ans.push_back(temp);
            return;
        }else if(sum>target) return;
        else{
            temp.push_back(candidates[ind]);
            solve(ind,sum+candidates[ind],target,candidates,temp);
            temp.pop_back();
            solve(ind+1,sum,target,candidates,temp);
            return;
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        solve(0,0,target,candidates,temp);
        return ans;
    }
};