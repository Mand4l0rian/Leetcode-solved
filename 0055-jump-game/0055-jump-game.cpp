class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxjump=0;
        int i=0;
        while(i<=maxjump){
            maxjump=max(maxjump,i+nums[i]);
            i++;
            if(maxjump>=n-1) return true;
        }
        return false;
    }
};