class Solution {
public:
    vector<vector<int>>directions = {{0,1},{1,0},{-1,0},{0,-1}};

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> dist(m,vector<int>(n,1e9));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,0,0});
        dist[0][0] = 0;
        while(!pq.empty())
        {
            auto p = pq.top();
            int diff = p[0];
            int r = p[1];
            int c = p[2];
            pq.pop();
            if(r == m-1 && c == n-1)
            {
                return diff;
            }
            if(dist[r][c] < diff) continue;
            for(auto d: directions)
            {
                int nr = r + d[0];
                int nc = c + d[1];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n)
                {
                    if(dist[r][c] != 1e9 && dist[nr][nc] > max(dist[r][c], abs(heights[nr][nc] - heights[r][c])))
                    {
                        dist[nr][nc] = max(dist[r][c], abs(heights[nr][nc]-heights[r][c]));
                        pq.push({dist[nr][nc],nr,nc});
                    }
                }
            }
        }
        return -1;    
    }
};