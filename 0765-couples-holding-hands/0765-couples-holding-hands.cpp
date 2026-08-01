class UnionFind
{
public:
    vector<int> parent,rank;
    UnionFind(int n)
    {
        parent.resize(n),rank.resize(n);
        for(int i = 0 ; i<n;i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    int Find(int x)
    {
        return parent[x] == x ? x : parent[x] = Find(parent[x]);
    }
    void Union(int u,int v)
    {
        u = Find(u), v = Find(v);
        if(u == v) return;
        if(rank[u] < rank[v])
        {
            parent[u] = v;
        }
        else if(rank[u] > rank[v])
        {
            parent[v] = u;
        }
        else
        {
            parent[u] = v;
            rank[v]++;
        }
        return;
        
    }
    int countcomponents()
    {
        unordered_set<int> s;
        for(int i = 0;i<parent.size();i++)
        {
            s.insert(Find(i));
        }
        return s.size();
    }

};

class Solution {
public:
    int Partner(int x)
    {
        if(x % 2 == 0) return x+1;
        return x - 1;
    }
    int findPartner(int x, vector<int>& row)
    {
        int y = Partner(x);
        auto it = find(row.begin(),row.end(),y);
        int idx = distance(row.begin(), it);
        return idx / 2;
    }
    int minSwapsCouples(vector<int>& row) {
        int n = row.size() / 2;
        UnionFind uf = UnionFind(n);
        for(int i = 0;i < n; i++)
        {
           int p1 = row[2*i];
           int p2 = row[2*i+1];
           if(Partner(p1) == p2) continue;
           uf.Union(i,findPartner(p1,row));
           uf.Union(i,findPartner(p2,row));

        }
        int count = uf.countcomponents();
        return n - count;
        
    }
};