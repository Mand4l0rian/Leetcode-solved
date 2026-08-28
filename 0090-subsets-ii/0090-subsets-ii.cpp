class Solution {
public:
    set<vector<int>> s;
    void solve(int ind, vector<int>& nums, vector<int>& temp){
        if(ind==nums.size()){
            s.insert(temp);
            return;
        }
        temp.push_back(nums[ind]);
        solve(ind+1,nums,temp);
        temp.pop_back();
        solve(ind+1,nums,temp);
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        solve(0,nums,temp);
        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }
};