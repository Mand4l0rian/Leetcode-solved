class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;

        vector<int> left(n, -1);
        vector<int> right(n, n);

        // Previous smaller element
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (!st.empty()) {
                left[i] = st.top();
            }

            st.push(i);
        }

        // Next smaller element
        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if (!st.empty()) {
                right[i] = st.top();
            }

            st.push(i);
        }

        // Calculate contribution of each element
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long leftChoices = i - left[i];
            long long rightChoices = right[i] - i;

            ans = (ans + arr[i] * leftChoices * rightChoices) % MOD;
        }

        return ans;
    }
};