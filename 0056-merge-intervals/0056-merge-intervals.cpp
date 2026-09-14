// O(n) extra space excluding return vector
// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         vector<int> start;
//         vector<int> end;
//         for(int i=0;i<intervals.size();i++){
//             start.push_back(intervals[i][0]);
//             end.push_back(intervals[i][1]);
//         }
//         sort(start.begin(),start.end());
//         sort(end.begin(),end.end());
//         int low= start[0];
//         int high= end[0];
//         vector<vector<int>> ans;
//         for(int i=1;i<intervals.size();i++){
//             if(start[i]<=end[i-1]){
//                 high=end[i];
//             }
//             else{
//                 ans.push_back({low,high});
//                 low=start[i];
//                 high=end[i];
//             }
//         }
//         ans.push_back({low,high});
//         return ans;
//     }
// };

// O(1) space excluding return vector
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
sort(intervals.begin(), intervals.end());

vector<vector<int>> ans;

for (auto &interval : intervals) {
    if (ans.empty() || ans.back()[1] < interval[0]) {
        ans.push_back(interval);
    } else {
        ans.back()[1] = max(ans.back()[1], interval[1]);
    }
}

return ans;
    }
};