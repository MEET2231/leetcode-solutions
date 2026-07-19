class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<int>> matrix(n,vector<int>(n,1e9));
        for(auto e : edges)
        {
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            matrix[u][v] = wt;
            matrix[v][u] = wt;
        }
        for(int i = 0;i<n;i++)
        {
            matrix[i][i] = 0;
        }

        for(int k = 0;k<n;k++)
        {
            for(int i = 0;i<n;i++)
            {
                for(int j = 0;j<n;j++)
                {
                    if(matrix[i][k] != 1e9 && matrix[k][j] != 1e9)
                    {
                        matrix[i][j] = min(matrix[i][j],matrix[i][k] + matrix[k][j]);
                    }
                }
            }
        }
        int MIN = INT_MAX;
        int city = 0;
        for(int i = 0;i<n;i++)
        {
            int count = 0;
            for(int j = 0;j<n;j++)
            {
                if(matrix[i][j] <= distanceThreshold) count++;
            }
            if(count <= MIN)
            {
                MIN = count;
                city = i;
            }
            // else if (count == MIN)
            // {
            //     city = max(city,i);
            // }
        }
        return city;
    }
};