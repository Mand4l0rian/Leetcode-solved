// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if (s.size() != t.size())
//             return false;

//         int count[26] = {0};

//         for (int i = 0; i < s.size(); i++) {
//             count[s[i] - 'a']++;
//             count[t[i] - 'a']--;
//         }

//         for (int i = 0; i < 26; i++) {
//             if (count[i] != 0)
//                 return false;
//         }

//         return true;
//     }
// };

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mpp;
        if(s.size()!=t.size()) return false;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        for(int j=0;j<t.size();j++){
            if(mpp[t[j]]>0) mpp[t[j]]--;
            else return false;
        }
        return true;
    }
};