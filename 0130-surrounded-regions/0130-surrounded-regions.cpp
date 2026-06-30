class Solution {
public:
    int M,N;
    void dfs(int i,int j,vector<vector<char>>& board, vector<vector<bool>>& vis )
    {
        if(i<0 || j<0 || i>=M || j>=N ||vis[i][j] == true || board[i][j] == 'X') return;
        vis[i][j] = true;
        dfs(i+1,j,board,vis);
        dfs(i,j+1,board,vis);
        dfs(i-1,j,board,vis);
        dfs(i,j-1,board,vis);

    }
    void solve(vector<vector<char>>& board) {
        M = board.size();
        N = board[0].size();
        vector<vector<bool>> vis(M,vector<bool>(N,false));
        for(int i =0; i<M;i++)
        {
            if(board[i][0] == 'O' && vis[i][0] == false)
            {
                dfs(i,0,board,vis);
            }
            if(board[i][N-1] == 'O' && vis[i][N-1] == false)
            {
                dfs(i,N-1,board,vis);
            }
        }

        for(int j=0;j<N;j++)
        {
            if(board[0][j] == 'O' && vis[0][j] == false)
            {
                dfs(0,j,board,vis);
            }
            if(board[M-1][j] == 'O' && vis[M-1][j] == false)
            {
                dfs(M-1,j,board,vis);
            }
        }
        for(int i = 0;i<M;i++)
        {
            for(int j = 0;j<N;j++)
            {
                if(board[i][j] == 'O' && vis[i][j] == false)
                {
                    board[i][j] = 'X';
                }
            }
        }
        

    }
};