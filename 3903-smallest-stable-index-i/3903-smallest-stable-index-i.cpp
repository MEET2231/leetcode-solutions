class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> premax(n+1);
        premax[0] = nums[0];
        for(int i = 1 ;i<n;i++ )
        {
            premax[i] = max(nums[i],premax[i-1]);
        }
        vector<int> postmin(n+1,0);
        postmin[n-1] = nums[n-1];
        for(int i = n-2;i>=0;i--){
            postmin[i] = min(nums[i],postmin[i + 1]);
        }
        for(int i = 0;i<n;i++)
        {
            if(premax[i]-postmin[i] <= k)
            {
                return i;
            }
        }
        return -1;
        
    }
};