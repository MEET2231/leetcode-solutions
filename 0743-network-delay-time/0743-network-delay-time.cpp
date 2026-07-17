class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> grid(n+1);
        for( auto &t : times)
        {
            grid[t[0]].push_back({t[1],t[2]});
        }
        vector<int> distances(n+1,INT_MAX);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,k});
        distances[k] = 0;
        while(!pq.empty())
        {
            auto node = pq.top();
            pq.pop();

            for(auto & neighbor : grid[node[1]])
            {   
                int dist = node[0] + neighbor.second;
                if(distances[neighbor.first] > dist)
                {
                    distances[neighbor.first] = dist;
                    pq.push({dist,neighbor.first});
                }

            }
        }

        int ans = INT_MIN;
        for( int i = 1;i<=n;i++)
        {
            if(distances[i] == INT_MAX) return -1;
            ans = max(ans,distances[i]);
        }
        return ans;
    }
};