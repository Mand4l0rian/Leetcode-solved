class Solution {
public:

    void expand(string& s, int l, int r, int& start, int& maxLen) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {

            if (r - l + 1 > maxLen) {
                start = l;
                maxLen = r - l + 1;
            }

            l--;
            r++;
        }
    }

    string longestPalindrome(string s) {
        int start = 0;
        int maxLen = 1;

        for (int i = 0; i < s.size(); i++) {
            expand(s, i, i, start, maxLen);       // odd
            expand(s, i, i + 1, start, maxLen);   // even
        }

        return s.substr(start, maxLen);
    }
};