class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> mystack;
        unordered_map<int,int> mpp;
        for(int i=nums2.size()-1; i>=0; i--){
            int nge=-1;
            while(!mystack.empty()){
                if(mystack.top()<nums2[i]) mystack.pop();
                else break;
            }
            if(!mystack.empty()) nge=mystack.top();
            mystack.push(nums2[i]);
            mpp[nums2[i]]=nge;
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(mpp[nums1[i]]);
        }
        return ans;
    }
};