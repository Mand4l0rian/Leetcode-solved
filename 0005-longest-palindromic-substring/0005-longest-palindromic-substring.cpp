class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, maxLen = 1;

        auto expand = [&](int l, int r) {
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r - l + 1 > maxLen) {
                    start = l;
                    maxLen = r - l + 1;
                }
                l--;
                r++;
            }
        };

        for (int i = 0; i < s.size(); i++) {
            expand(i, i);       // odd length
            expand(i, i + 1);   // even length
        }

        return s.substr(start, maxLen);
    }
};