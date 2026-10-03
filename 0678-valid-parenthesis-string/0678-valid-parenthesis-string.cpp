class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;   // minimum possible unmatched '('
        int high = 0;  // maximum possible unmatched '('

        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            }
            else if (c == ')') {
                low--;
                high--;
            }
            else { // '*'
                low--;   // treat '*' as ')'
                high++;  // treat '*' as '('
            }

            if (high < 0)
                return false;

            low = max(low, 0);
        }

        return low == 0;
    }
};