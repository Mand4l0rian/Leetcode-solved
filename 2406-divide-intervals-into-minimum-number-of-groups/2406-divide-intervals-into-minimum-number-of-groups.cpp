class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> start, end;

        for (auto &x : intervals) {
            start.push_back(x[0]);
            end.push_back(x[1]);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int i = 0, j = 0;
        int active = 0;
        int ans = 0;

        while (i < start.size()) {
            if (start[i] <= end[j]) {
                active++;
                ans = max(ans, active);
                i++;
            }
            else {
                active--;
                j++;
            }
        }

        return ans;
    }
};