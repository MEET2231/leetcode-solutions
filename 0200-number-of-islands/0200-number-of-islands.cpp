class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> directions{{1,0},{0,1},{-1,0},{0,-1}};
        int count = 0;

        for(int i = 0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == '1')
                {
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    while(!q.empty())
                    {
                        auto node = q.front();

                        q.pop();
                        for(auto & d: directions)
                        {
                            int nr = node.first + d[0];
                            int nc = node.second + d[1];
                            if(nr>=0 && nr<m && nc >= 0 && nc < n && grid[nr][nc] == '1' )
                            {
                                q.push({nr,nc});
                                grid[nr][nc] = '0';
                            }
                        }
                    }
                    count++;
                }
            }
        }
        return count;
    }

};