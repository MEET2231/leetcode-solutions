class Solution {
public:
    int N,M;
    vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
    // void bfs(int i,int j,vector<vector<int>>& mat,vector<vector<int>>& ans)
    // {
    //     queue<pair<int,int>> q;
    //     q.push({i,j});
    //     bool found = false;
    //     int distance = 0;
    //     while(!q.empty() && !found)
    //     {
    //         int S = q.size();
    //         for(int _ = 0;_<S;_++)
    //         {
    //             int r = q.front().first;
    //             int c = q.front().second;
    //             q.pop();
    //             if(mat[r][c] == 0)
    //             {
    //                 ans[i][j] = distance;
    //                 return;
    //             }
    //             for(auto& d : directions)
    //             {
    //                 int nr = r + d[0];
    //                 int nc = c + d[1];
    //                 if(nr>=0 && nr <M && nc >=0 && nc < N)
    //                 {
    //                     q.push({nr,nc});
    //                 } 
    //             }
    //         }
    //         distance++;
    //     }
    //     return;


    // }   
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n,m;
        m = mat.size();
        M = m;
        n = mat[0].size();
        N=n;
        queue<pair<int,int>> q;
        for(int r=0;r<m;r++)
        {
            for(int c =0;c<n;c++)
            {
                if(mat[r][c] == 0) q.push({r,c});
                else mat[r][c] = -1;
            }
        }

        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(auto& d : directions)
            {
                int nr = r + d[0];
                int nc = c + d[1];
                if(nr >=0 && nr<m && nc>=0 && nc < n && mat[nr][nc] == -1)
                {
                    mat[nr][nc] = mat[r][c] + 1;
                    q.push({nr,nc});
                }
            }
        }
        return mat;
        
    }
};