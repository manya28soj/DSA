class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>result;
        for(int i =0; i<nums.size(); i++){
            //removal out of window
            if(!dq.empty() && dq.front()<= i-k)
            dq.pop_front();

            //remove smaller elemnt
            while(!dq.empty() && nums[dq.back()]<nums[i])
            dq.pop_back();

            //insert current index
            dq.push_back(i);

            //store ans
            if(i>=k-1)
            result.push_back(nums[dq.front()]);
        }
        return result;
    }
};