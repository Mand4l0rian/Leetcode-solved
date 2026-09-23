class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = accumulate(cardPoints.begin(),cardPoints.end(), 0);
        int windowSize = n - k;

        // If k == n, take everything
        if (windowSize == 0) return total;
        int windowSum = 0;

        // First window
        for (int i = 0; i < windowSize; i++) {
            windowSum += cardPoints[i];
        }
        int minWindow = windowSum;

        // Sliding window
        for (int i = windowSize; i < n; i++) {
            windowSum += cardPoints[i];
            windowSum -= cardPoints[i - windowSize];
            minWindow = min(minWindow, windowSum);
        }
        return total - minWindow;
    }
};