class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        int MAX = INT_MIN;
        int MAX_idx = 0;
        for(int i = 0;i<k;i++)
        {
            if(nums[i] >= MAX)
            {
                MAX = nums[i];
                MAX_idx = i;
            }
        }
        ans.push_back(MAX);

        int left = 0,right = k-1;
        while(right < n-1)
        {
            right++;
            if(nums[right] > nums[MAX_idx])
            {
                MAX = nums[right];
                MAX_idx = right;
            }
            if(nums[right] < nums[MAX_idx])
            {
                if(MAX_idx == left)
                {
                    MAX = nums[left+1];
                    MAX_idx = left + 1;
                    for(int i = left+2;i<=right;i++)
                    {
                        if(nums[i] >= MAX)
                        {
                            MAX = nums[i];
                            MAX_idx = i;
                        }
                    }
                }
            }
            if(nums[right] == nums[MAX_idx])
            {
                if(MAX_idx == left)
                {
                    MAX_idx = right;
                }
            }
            left++;
            ans.push_back(MAX);
        }     
        return ans; 
    }
};