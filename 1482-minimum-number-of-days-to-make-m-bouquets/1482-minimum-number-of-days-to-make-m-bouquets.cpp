class Solution {
public:
    int func(vector<int>& bloomDay, int days, int bouquet_size){
        int count=0;
        int tempcount=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=days){
                tempcount++;
            }
            else tempcount=0;
            if(tempcount==bouquet_size){
                count++;
                tempcount=0;
            }
        }
        return count;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int ans=-1;
        long long mul = (long long)m * k;
        if(bloomDay.size()<mul) return ans;
        int low=1;
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high){
            int mid=(low+high)/2;
            if(func(bloomDay,mid,k)<m){
                low=mid+1;
            }else{
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};