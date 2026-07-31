class Solution {
public:
    int M,N;
    vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
    int max_island_size = 0;
    int getnode(int i , int j)
    {
        return N*i + j;
    }
    int makeisland(int i,int j,vector<vector<int>>& visited,vector<int>& parent,vector<vector<int>>& grid)
    {
        int count = 0;
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j] = 1;
        count++;
        while(!q.empty())
        {
            auto [r,c] = q.front();q.pop();
            parent[getnode(r,c)] = getnode(i,j);
            for(auto d: dir)
            {
                int nr = r + d[0];
                int nc = c + d[1];
                if(nr >= 0 && nr < M && nc >= 0 && nc < N && grid[nr][nc] == 1 && !visited[nr][nc])
                {
                    q.push({nr,nc});
                    visited[nr][nc] = 1;
                    count++;
                }
            }
        }
        max_island_size = max(max_island_size,count);
        return count;

    }
    int largestIsland(vector<vector<int>>& grid) {
        M = grid.size();
        N = grid[0].size();
        vector<int> count(M*N);
        vector<vector<int>> visited(M,vector<int>(N));
        vector<int>parent(M*N);
        for(int i = 0;i<M*N;i++)
        {
            parent[i] = i;
        }
        for(int i = 0;i<M;i++)
        {
            for(int j = 0;j<N;j++)
            {
                if(grid[i][j] != 0 && !visited[i][j])
                {
                    count[getnode(i,j)] = makeisland(i,j,visited,parent,grid);
                }
            }
        }
        if(max_island_size == M*N) return M*N;

        int MAX = INT_MIN;
        for(int i = 0;i<M;i++)
        {
            for(int j = 0;j<N;j++)
            {
                int Sum = 0;
                unordered_set<int> considered;
                if(grid[i][j] == 0)
                {
                    for(auto d : dir)
                    {
                        int nr = i + d[0];
                        int nc = j + d[1];
                        if(nr >= 0 && nr < M && nc >= 0 && nc < N && grid[nr][nc] == 1 && considered.count(parent[getnode(nr,nc)]) == 0)
                        {
                            Sum += count[parent[getnode(nr,nc)]];
                            considered.insert(parent[getnode(nr,nc)]);
                        }

                    }
                }
                MAX = max(Sum,MAX);

            }
        }
        return max(max_island_size, MAX + 1);
        
    }
};