class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            if(!s.count(nums[i])){
                s.insert(nums[i]);
            }else return true;
        }
        return false;
    }
};