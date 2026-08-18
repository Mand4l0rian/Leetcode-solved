class Solution {
public:
    string largestOddNumber(string num) {
        for(int i=num.length()-1;i>=0;i--){
            if(i==0 && num[0]%2==0) num="";
            if(num[i]%2==1){
                num=num.substr(0,i+1);
                break;
            }
        }
        return num;
    }
};