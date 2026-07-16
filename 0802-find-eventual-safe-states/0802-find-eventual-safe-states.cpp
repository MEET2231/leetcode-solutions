class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>outdegree(n,0);
        for(int i = 0;i<n;i++)
        {
            outdegree[i] = graph[i].size();
        }
        vector<vector<int>> graph_m(n);
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<graph[i].size();j++)
            {
                graph_m[graph[i][j]].push_back(i);
            }
        }
        queue<int>q;
        for(int i = 0;i<n;i++)
        {
            if(outdegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> ans;
        vector<bool> isSafe(n,false);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            isSafe[node] = true;
            for(auto i : graph_m[node])
            {
                outdegree[i]--;
                if(outdegree[i] == 0)
                {
                    q.push(i);
                }
            }
        }
        for(int i =0;i<n;i++)
        {
            if(isSafe[i])
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};