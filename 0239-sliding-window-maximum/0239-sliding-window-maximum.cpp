// use deque, store indices in a monotonic decreasing sequence, at each iteration, insert into deque while maintaining the monotonic property, the front of the queue thus becomes the index storing the largest element, check whether the front index is in range of the window, and if not then pop from front till we obtain the largest element which is in the current range, and then push the element into the ans vector.
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