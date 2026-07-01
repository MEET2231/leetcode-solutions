class Solution {
public:
    int M,N;
    vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
    void dfs(int r,int c,vector<vector<int>>& grid)
    {
        grid[r][c] = -1;
        for(auto& d:directions)
        {
            int nr = r + d[0];
            int nc = c + d[1];
            if(nr>=0 && nr<M && nc>=0 && nc<N && grid[nr][nc] == 1)
            {
                dfs(nr,nc,grid);
            }
        }

    }
    int numEnclaves(vector<vector<int>>& grid) {
        M = grid.size();
        N = grid[0].size();

        for(int i =0;i<M;i++)
        {
            if(grid[i][0] == 1)
            {
                dfs(i,0,grid);
            }
            if(grid[i][N-1] == 1)
            {
                dfs(i,N-1,grid);
            }
        }
        for(int j = 0;j<N;j++)
        {
            if(grid[0][j] == 1)
            {
                dfs(0,j,grid);
            }
            if(grid[M-1][j] == 1)
            {
                dfs(M-1,j,grid);
            }
        }
        int count;
        for(int i =0;i<M;i++)
        {
            for(int j = 0;j<N;j++)
            {
                if(grid[i][j] == 1) count++;
            }
        }
        return count;
        
    }
};