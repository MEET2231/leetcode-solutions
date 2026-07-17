class Solution {
public:
    vector<vector<int>> directions = {{0,1},{1,0},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> marked(n,vector<int>(n,0));
        int ans = 0;
        queue<pair<int,int>>q;
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        q.push({0,0});
        while(!q.empty())
        {   
            int S = q.size();
            for(int _ =0;_<S;_++)
            {
                auto node = q.front();q.pop();
                if(node.first == n-1 && node.second == n-1)
                {
                    return ans+1;
                }
                for(auto &d :directions)
                {
                    int nr = node.first +d[0];
                    int nc = node.second + d[1];
                    if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0 && !marked[nr][nc])
                    {
                        q.push({nr,nc});
                        marked[nr][nc] = 1;
                    }
                }
            }
            ans++;


        }
        return -1;

        
    }
};