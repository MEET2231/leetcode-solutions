class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1 ) return -1;
        vector<vector<int>>adj(n);
        int count = 0;
        for(auto c : connections)
        {
            int i = c[0];
            int j = c[1];
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
        vector<bool> visited(n,false);
        int connected_comp = 0;
        for(int i = 0;i<n;i++)
        {   
            if(!visited[i])
            {
                connected_comp++;
                queue<int> q;
                q.push(i);
                visited[i] = true;
                while(!q.empty())
                {
                    int u = q.front();q.pop();
                    for(auto v : adj[u])
                    {
                        if(!visited[v])
                        {
                            visited[v] = true;
                            q.push(v);
                        } 
                    }
                }
            }
        }
        return connected_comp - 1;


        
    }
};