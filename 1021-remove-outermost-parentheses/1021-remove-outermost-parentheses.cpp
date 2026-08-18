class Solution {
public:
    string primconv(string& temp){
        string converted;
        if(temp.length()==2) return converted;
        converted=temp.substr(1,temp.length()-2);
        return converted;
    }
    string removeOuterParentheses(string s) {
        int len=s.length();
        stack<char> stack;
        string ans;
        string temp;
        for(int i=0;i<len;i++){
            if(stack.empty()){
                temp=(s[i]);
                stack.push(s[i]);
            }else{
                temp.push_back(s[i]);
                if(s[i]=='(') stack.push(s[i]);
                else stack.pop();
                if(stack.empty()){
                    ans=ans+primconv(temp);
                }
            }
        }
        return ans;
    }
};