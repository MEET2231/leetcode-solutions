class Solution {
public:
    int maxArea(vector<int>& height) {
         int n = height.size();
         int i = 0,j= n-1;
         int MAX = 0;
         while(i<j)
         {
            int vol = min(height[i],height[j]) * (j-i);
            MAX = max(vol,MAX);
            if(height[i] < height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
         }
         return MAX;
        
    }
};