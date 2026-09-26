class Solution {
public:
    int maxDepth(string s) {
        int i=0;
        int ans=0;
        int curr=0;
        while(i!=s.length()){
            if(s[i]=='('){
                curr++;
                ans=max(ans,curr);
            }
            else if(s[i]==')') curr--;
            i++;
        }
        return ans;
    }
};