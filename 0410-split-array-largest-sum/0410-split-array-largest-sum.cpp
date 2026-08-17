class Solution {
public:
    int func(vector<int>& nums, int capacity){
        int subarray_count=1;
        int remaining=capacity;
        for(int num:nums){
            if(num<=remaining){
                remaining-=num;
            }else{
                subarray_count++;
                remaining=capacity-num;
            }
        }
        return subarray_count;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            if(func(nums,mid)>k){
                low=mid+1;
            }else high=mid-1;
        }
        return low;
    }
};