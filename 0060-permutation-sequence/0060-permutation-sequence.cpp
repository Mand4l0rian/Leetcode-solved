class Solution {
public:
    string getPermutation(int n, int k) {
        string s = "";
        for (int i = 1; i <= n; i++) {
            s += char('0' + i);
        }
        for (int i = 1; i < k; i++) {
            next_permutation(s.begin(), s.end());
        }
        return s;
    }
};