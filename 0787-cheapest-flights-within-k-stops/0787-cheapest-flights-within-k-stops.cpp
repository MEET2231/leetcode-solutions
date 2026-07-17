class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &f : flights) adj[f[0]].push_back({f[1],f[2]});
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> pq;

        vector<int> min_stops(n,INT_MAX);
        pq.push({0,src,0});
        while(!pq.empty())
        {
            auto [cost,u,stops] = pq.top();
            pq.pop();
            if(u == dst) return cost;
            if(stops >= min_stops[u]) continue;
            min_stops[u] = stops;
            if(stops > k) continue;
            for(auto & [v,wt] : adj[u])
            {
                pq.push({cost+wt,v,stops+1});
            }
        }
        return -1;

        
    }
};