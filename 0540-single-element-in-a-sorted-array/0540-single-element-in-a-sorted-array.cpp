class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        int ans=0;
        while(low<=high){
            if(low==high) {ans=nums[high]; break;}
            int mid=(low+high)/2;
            if(mid%2==0){
                if(nums[mid]==nums[mid+1]){
                    low=mid+2;
                }else{
                    high=mid;
                }
            }else{
                if(nums[mid]==nums[mid-1]){
                    low=mid+1;
                }else{
                    high=mid;
                }
            }
        }
        return ans;
    }
};