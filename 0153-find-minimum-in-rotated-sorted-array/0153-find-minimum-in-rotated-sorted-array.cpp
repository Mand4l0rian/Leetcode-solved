class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int ans = INT_MAX;
// find which part is the sorted part and then update a global variable ans initialized to INT_MAX
// by comparing it to the minimum value in the sorted part and taking the minimum of those two

// repeatedly compare the minimum elements of all the sorted parts until found the most minimum of
// the minimums at the last
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[low]<=nums[high]){
                ans=min(ans,nums[low]);
                break;
            }
            if (nums[low] <= nums[mid]) {
                ans = min(ans, nums[low]);
                low = mid + 1;
            } else {
                high = mid - 1;
                ans = min(ans, nums[mid]);
            }
        }

        return ans;
    }
};