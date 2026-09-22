class Solution {
public:
    long long hoursNeeded(vector<int>& piles, int k) {
        long long hours = 0;
        for (int bananas : piles) {
            hours += (bananas-1)/k +1;
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = *max_element(piles.begin(), piles.end());
        int low=1;
        while(low<=high){
            int mid=(low+high)/2;
            if(hoursNeeded(piles,mid)<=h){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};