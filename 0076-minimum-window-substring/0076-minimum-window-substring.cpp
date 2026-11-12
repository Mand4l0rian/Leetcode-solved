// idea is simple, we know what to do but this map approach is difficult to produce:
// just focus on: using a map and required integer, map has -ve values for the char in window which are not a part of characters which are required and the required characters have +ve values,
// we thus find the "start" which is the starting point of the window which we seek to find and "minlength" is the length of the corresponding window. 
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;

        for (char c : t) {
            mp[c]++;
        }

        int left = 0, required = t.size();
        int start = 0, minLen = INT_MAX;

        for (int right = 0; right < s.size(); right++) {
            if (mp[s[right]] > 0) {
                required--;
            }
            mp[s[right]]--;

            while (required == 0) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                mp[s[left]]++;

                if (mp[s[left]] > 0) {
                    required++;
                }

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
