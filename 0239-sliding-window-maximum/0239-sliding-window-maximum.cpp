class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        for(int i=0;i<k-1;i++){
            while(!q.empty()){
                if(nums[q.back()]<nums[i]) q.pop_back();
                else break;
            }
            q.push_back(i);
        }
        vector<int> ans;
        for(int i=k-1;i<nums.size();i++){
            while(!q.empty()){
                if(nums[q.back()]<nums[i]) q.pop_back();
                else break;
            }
            q.push_back(i);
            while(!q.empty()){
                if(q.front()>=i-k+1){
                    ans.push_back(nums[q.front()]);
                    break;
                }else q.pop_front();
            }
        }
        return ans;
    }
};