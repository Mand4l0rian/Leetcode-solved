class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map <int,int> um;
        int maxconsecutive=0;
        for(int i=0; i<nums.size();i++){
            if(um.find(nums[i])!=um.end()) continue;
            um[nums[i]]=1;
            int left=0;
            int right=0;
            if(um.find(nums[i]+1)!=um.end()) right=um[nums[i]+1];
            if(um.find(nums[i]-1)!=um.end()) left=um[nums[i]-1];
            int length=left+right+1;
            um[nums[i]+right]=length;
            um[nums[i]-left]=length;
            if(maxconsecutive<length) maxconsecutive=length;
        }
        return maxconsecutive;
    }
};