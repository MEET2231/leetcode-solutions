class Solution {
public:
    void dfs(string node,string dest,unordered_map<string,unordered_map<string,double>> & graph,unordered_set<string> & vis,double & ans, double temp )
    {
        if(vis.find(node) != vis.end()) return;
        vis.insert(node);
        if(node == dest)
        {
            ans = temp;
            return;
        }
        for(auto ne : graph[node])
        {
            dfs(ne.first,dest,graph,vis,ans,temp*ne.second);
        }

    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        unordered_map<string,unordered_map<string,double>> graph;
        for(int i = 0;i<equations.size();i++)
        {
            string dividend = equations[i][0];
            string divisor = equations[i][1];
            double value = values[i];
            graph[dividend][divisor] = value;
            graph[divisor][dividend] = 1.0 / value; 
        }
        vector<double> Finalans;
        for(auto q : queries)
        {
            string dividend = q[0];
            string divisor  = q[1];
            if(graph.find(dividend) == graph.end() || graph.find(divisor) == graph.end())
            {
                Finalans.push_back(-1.0);
                continue;
            }
            unordered_set<string> visited;
            double ans = -1,temp = 1.0;
            dfs(dividend,divisor,graph,visited,ans,temp);
            Finalans.push_back(ans);
        }
        return Finalans;

        
    }
};