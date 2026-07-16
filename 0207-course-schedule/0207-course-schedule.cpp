class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> mp(numCourses);
        vector<int> count(numCourses,0);
        
        for(auto& i:prerequisites){
            mp[i[1]].push_back(i[0]);
            count[i[0]]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(count[i] == 0) q.push(i);
        }
        if(q.empty()) return false;
        int visited  = 0;
        while(!q.empty())
        {
            int node = q.front(); q.pop();
            visited++;
            for(auto & neighbour : mp[node])
            {
                count[neighbour]--;
                if(count[neighbour] == 0)
                {
                    q.push(neighbour);
                }
            }
        }
        return numCourses == visited;



    
        }
    
};