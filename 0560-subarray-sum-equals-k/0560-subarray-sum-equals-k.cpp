class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        um[0]=1;
        int sum=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int need=sum-k;
            if(um.find(need)!=um.end()){
                count+=um[need];
            }
            um[sum]++;
        }
        return count;
    }
};