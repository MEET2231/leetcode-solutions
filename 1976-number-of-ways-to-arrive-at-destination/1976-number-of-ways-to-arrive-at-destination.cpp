class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,long long>>> adj(n);
        long long MOD = 1e9 + 7;
        int ans = 0;
        for(auto & r : roads)
        {
            adj[r[0]].push_back({r[1],r[2]});
            adj[r[1]].push_back({r[0],r[2]});
        }

        vector<long long> time(n,LLONG_MAX);
        vector<long long> paths(n,0);
        priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>>pq;
        pq.push({0,0}); //{time,node}
        time[0] = 0;
        paths[0] = 1;

        while(!pq.empty())
        {
            auto node = pq.top();
            pq.pop();
            if(node[0] > time[node[1]]) continue;

            for(auto & i : adj[node[1]])
            {
                if(time[i.first] > node[0] + i.second)
                {
                    time[i.first] = node[0] + i.second;
                    paths[i.first] = paths[node[1]] % MOD;
                    pq.push({time[i.first],i.first});
                }
                else if(time[i.first] == node[0] + i.second)
                {
                    paths[i.first] = (paths[i.first] + paths[node[1]]) % MOD;
                }

            }

        }
        return paths[n-1];

    }
};