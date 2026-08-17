class Solution {
public:
    int func(vector<int>& weights, int capacity){
        int days=1;
        int buffer=capacity;
        for(int weight:weights){
            if(weight<=buffer){
                buffer=buffer-weight;
            }else{
                days++;
                buffer=capacity-weight;
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(func(weights,mid)>days){
                low=mid+1;
            }else{
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};