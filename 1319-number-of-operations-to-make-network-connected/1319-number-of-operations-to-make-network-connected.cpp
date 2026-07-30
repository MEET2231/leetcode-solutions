class Solution {
public:
    int findParent(int i,vector<int> & parent)
    {
        if(parent[i] == i) return i;
        return parent[i] = findParent(parent[i],parent);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        vector<int> parent(n);
        for(int i = 0;i<n;i++)
        {
            parent[i] = i;
        }
        int components = n;
        for(auto & conn : connections)
        {
            int u = findParent(conn[0],parent);
            int v = findParent(conn[1],parent);

            if(u == v) continue;
            parent[u] = v;
            components--;
        }
        return components-1;


    }
};