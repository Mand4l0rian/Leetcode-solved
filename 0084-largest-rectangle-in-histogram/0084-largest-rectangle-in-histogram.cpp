class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse(heights.size(),heights.size());
        stack<int> s;
        for(int i=heights.size()-1;i>=0;i--){
            while(!s.empty()){
                if(heights[s.top()]>=heights[i]) s.pop();
                else break;
            }
            if(!s.empty()) nse[i]=s.top();
            s.push(i);
        }
        vector<int> pse(heights.size(),-1);
        stack<int> st;
        for(int i=0;i<heights.size();i++){
            while(!st.empty()){
                if(heights[st.top()]>=heights[i]) st.pop();
                else break;
            }
            if(!st.empty()) pse[i]=st.top();
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<heights.size();i++){
            ans=max(ans,heights[i]*(nse[i]-pse[i]-1));
        }
        return ans;
    }
};