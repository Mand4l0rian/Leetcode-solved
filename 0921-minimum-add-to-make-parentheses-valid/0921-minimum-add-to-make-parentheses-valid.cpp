class Solution {
public:
    int minAddToMakeValid(string s) {
        int i=0;
        int open=0;
        int count=0;
        while(i!=s.length()){
            if(s[i]=='(') open++;
            else{
                if(open==0) count++;
                else open--;
            }
            i++;
        }
        count+=open;
        return count;
    }
};