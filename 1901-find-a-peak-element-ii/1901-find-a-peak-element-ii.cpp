class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int left = 0;
        int right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Find maximum element in column mid
            int maxRow = 0;

            for (int i = 1; i < m; i++) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }

            // Values outside the matrix are -1
            int leftVal = (mid > 0) ? mat[maxRow][mid - 1] : -1;
            int rightVal = (mid < n - 1) ? mat[maxRow][mid + 1] : -1;

            // We found a peak
            if (mat[maxRow][mid] > leftVal &&
                mat[maxRow][mid] > rightVal) {
                return {maxRow, mid};
            }

            // Left neighbor is greater
            if (leftVal > mat[maxRow][mid]) {
                right = mid - 1;
            }
            // Right neighbor is greater
            else {
                left = mid + 1;
            }
        }

        return {-1, -1};
    }
};