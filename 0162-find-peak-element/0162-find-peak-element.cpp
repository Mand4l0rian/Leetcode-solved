class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < nums[mid + 1]) {
                // We are going uphill.
                // A peak must exist on the right.
                left = mid + 1;
            }
            else {
                // We are going downhill.
                // mid itself could be a peak,
                // so keep mid.
                right = mid;
            }
        }

        return left;
    }
};