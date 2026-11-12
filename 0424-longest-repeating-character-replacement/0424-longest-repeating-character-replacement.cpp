class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);

        int left = 0;
        int maxFreq = 0;
        int maxLen = 0;

        for (int right = 0; right < s.size(); right++) {

            freq[s[right] - 'A']++;

            maxFreq = max(maxFreq, freq[s[right] - 'A']);
// hard optimizations (watch striver video last part for more info).
// 2 optimizations:
// 1) removing a loop which updates the maxfreq and maintains it for current valid window, instead we let the maxfreq be and not update it as we only want a higher maxfreq which will give us a better answer
// 2) removing the loop for shrinking the size of the window since we only want the next higher window size and thus decrementing it more and finding a valid window will not lead to a better answer than before so we just shrink it by only one size using the if statement instead of multiple times using the while loop. 
            // Invalid window
            if ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};