class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double sum = 0;
        double AVG = INT_MIN;
        for(int i = 0;i<k;i++)
        {
            sum += nums[i];
        }
        AVG = max(AVG, sum / k);
        for(int i = k;i<n;i++)
        {
            sum += nums[i] - nums[i-k];
            AVG = max(AVG,sum / k);
        }
        return AVG;
        
    }
};