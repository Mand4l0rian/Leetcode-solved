class Solution {
public:
    string largestOddNumber(string num) {
        string ans;
        for(int i=num.length()-1;i>=0;i--){
            if(num[i]%2==1){
                for(int j=0;j<=i;j++){
                    ans.push_back(num[j]);
                }
                break;
            }
        }
        return ans;
    }
};