class Solution {
public:
    string reverseWords(string& s) {

        // Step 1: Remove extra spaces in-place
        int write = 0;
        int n = s.size();

        for (int read = 0; read < n; read++) {

            // Skip spaces at the beginning
            if (s[read] == ' ' && write == 0)
                continue;

            // Don't allow multiple spaces
            if (s[read] == ' ' && s[write - 1] == ' ')
                continue;

            s[write++] = s[read];
        }

        // Remove trailing space
        if (write > 0 && s[write - 1] == ' ')
            write--;

        s.resize(write);

        // Step 2: Reverse entire string
        reverse(s.begin(), s.end());

        // Step 3: Reverse every individual word
        int start = 0;

        for (int i = 0; i <= s.size(); i++) {

            if (i == s.size() || s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }

        return s;
    }
};