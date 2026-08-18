// tc=O(N^2), sc=O(N)
// class Solution {
// public:
//     bool rotateString(string s, string goal) {
//         if (s.size() != goal.size())
//             return false;

//         int n = s.size();

//         for (int k = 0; k < n; k++) {
//             string temp = s.substr(k) + s.substr(0, k);

//             if (temp == goal)
//                 return true;
//         }

//         return false;
//     }
// };

// tc=implementation dependent on where the substring goal lies in s+s, but worst case is O(N^2), sc=O(N), for tc=O(N) use KMP, Z-algorithm
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size())
            return false;

        return (s + s).find(goal) != string::npos;
    }
};