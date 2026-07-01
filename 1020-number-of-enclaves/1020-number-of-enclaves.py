class Solution:
    def numEnclaves(self, grid: List[List[int]]) -> int:
        M = len(grid)
        N = len(grid[0])
        directions = [[0,1],[1,0],[-1,0],[0,-1]]

        def dfs(r : int,c : int) -> None:
            grid[r][c] = -1
            for d in directions:
                nr = r + d[0]
                nc = c + d[1]
                if 0<=nr<M and 0<=nc<N and grid[nr][nc] == 1 :
                    dfs(nr,nc)
            return 

        for i in range(M):
            if grid[i][0] == 1:
                dfs(i,0)
            if grid[i][N-1] == 1:
                dfs(i,N-1)

        for j in range(N):
            if grid[0][j] == 1:
                dfs(0,j)
            if grid[M-1][j] == 1:
                dfs(M-1,j)
        count = 0
        for i in range(M):
            for j in range(N):
                if grid[i][j] == 1:
                    count += 1

        return count
        