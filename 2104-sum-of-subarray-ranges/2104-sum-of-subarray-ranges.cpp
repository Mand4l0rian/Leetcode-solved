class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        vector<int> pse(n), nse(n);
        vector<int> pge(n), nge(n);

        stack<int> st;

        // PSE - Previous Smaller Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();

            if (st.empty())
                pse[i] = -1;
            else
                pse[i] = st.top();

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // NSE - Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i])
                st.pop();

            if (st.empty())
                nse[i] = n;
            else
                nse[i] = st.top();

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // PGE - Previous Greater Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] <= nums[i])
                st.pop();

            if (st.empty())
                pge[i] = -1;
            else
                pge[i] = st.top();

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // NGE - Next Greater Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i])
                st.pop();

            if (st.empty())
                nge[i] = n;
            else
                nge[i] = st.top();

            st.push(i);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {

            // Contribution as minimum
            long long minContribution =
                1LL * nums[i] *
                (i - pse[i]) *
                (nse[i] - i);

            // Contribution as maximum
            long long maxContribution =
                1LL * nums[i] *
                (i - pge[i]) *
                (nge[i] - i);

            ans += maxContribution - minContribution;
        }

        return ans;
    }
};