class Solution {
public:
    int count(vector<vector<int>> & img1,vector<vector<int>> & img2,int r,int c)
    {
        int n = img1.size();
        int count = 0;
        for(int i =0 ;i < n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                int nr = i + r;
                int nc = j + c;

                if(nr >= 0 && nr < n && nc >= 0 && nc < n)
                {
                    if(img1[i][j] == 1 && img2[nr][nc] == 1)
                    {
                        count++;
                    }
                }
            }
        }
        return count;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int MAX = 0;
        for(int i = -n + 1;i<=n-1;i++)
        {
            for(int j = -n + 1;j <= n-1;j++)
            {
                MAX = max(MAX,count(img1,img2,i,j));
            }
        }
        return MAX;
        
    }
};