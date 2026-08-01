class UnionFind {
    vector<int>parent,rank;
public:
    UnionFind(int n)
    {
        parent.resize(n), rank.resize(n);
        for(int i = 0;i<n;i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    int Find(int x)
    {
        return (x == parent[x]) ? x : parent[x] = Find(parent[x]);
    }
    bool Union(int u, int v)
    {
        u = Find(u), v = Find(v);
        if(u == v) return false;
        if(rank[v] > rank[u]){
            parent[u] = v;
        }
        else if(rank[u] > rank[v]) {
            parent[v] = u;
        }
        else
        {
            parent[u] = v;
            rank[v] ++;
        }
        return true;

    }

};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> in_parent(n+1,0);
        vector<int> cand1;
        vector<int> cand2;

        for(auto e : edges)
        {
            int u = e[0];
            int v = e[1];
            if(in_parent[v] != 0)
            {
                cand1 = {in_parent[v],v};
                cand2 = {u,v};
                break;
            }
            in_parent[v] = u;
        }

        UnionFind uf(n+1);
        for(auto & e : edges)
        {
            if(!cand2.empty() && e[0] == cand2[0] && e[1] == cand2[1])
            {
                continue;
            }
            int u = e[0];
            int v = e[1];
            if(!uf.Union(u,v))
            {
                if(cand1.empty())
                {
                    return e;
                }
                else
                {
                    return cand1;
                }
            }
        }
        return cand2;
        
    }
};