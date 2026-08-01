class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int>> Nums(n);
        for(int i = 0;i<n;i++)
        {
            Nums[i] = {nums[i],i}; 
        }
        sort(Nums.begin(),Nums.end());
        
        int i = 0;
        int j = n-1;
        while(i < j)
        {
            int sum = Nums[i].first + Nums[j].first;
            if(sum == target) return {Nums[i].second,Nums[j].second};
            if(sum < target) i++;
            else j--;
        }
        return {};
        
    }
};