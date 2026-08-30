class Solution {
public:
    bool isValid(string s) {
        stack<int> mystack;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') mystack.push(1);
            else if(s[i]=='{') mystack.push(2);
            else if(s[i]=='[') mystack.push(3);
            else if(s[i]==')'){
                if(mystack.empty()) return false;
                else if(mystack.top()==1) mystack.pop();
                else return false;
            }else if(s[i]=='}'){
                if(mystack.empty()) return false;
                else if(mystack.top()==2) mystack.pop();
                else return false;
            }else if(s[i]==']'){
                if(mystack.empty()) return false;
                else if(mystack.top()==3) mystack.pop();
                else return false;
            }
        }
        if(mystack.empty()) return true;
        else return false;
    }
};