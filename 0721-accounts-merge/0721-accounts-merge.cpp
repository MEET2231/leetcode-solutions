class Solution {
public:
    int find(int u,vector<int> & parents)
    {
        if(parents[u] == u) return u;
        return parents[u] = find(parents[u],parents);
    }
    void mkunion(int u,int v,vector<int> & parents)
    {
        u = find(u,parents), v = find(v,parents);
        if(u==v) return;
        parents[u] = v; 
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int> mp;
        int n = accounts.size();
        vector<int> parents(n);
        
        for(int i = 0;i<n;i++)
        {
            parents[i] = i;
        }
        for(int i=0;i<n;i++)
        {
            for(int j = 1;j<accounts[i].size();j++)
            {
                if(mp.find(accounts[i][j]) == mp.end()) mp[accounts[i][j]] = i;
                mkunion(i,mp[accounts[i][j]],parents);
            }
        }
        unordered_map<int, vector<string>> mergedmails;
        for(auto it : mp)
        {
            int p = find(it.second,parents);
            string mail = it.first;
            mergedmails[p].push_back(mail);

        }
        vector<vector<string>> ans;
        for (auto it : mergedmails) {
            int root = it.first;
            vector<string> emails = it.second;
            sort(emails.begin(), emails.end());
            vector<string> mergedAccount;
            mergedAccount.push_back(accounts[root][0]);
            mergedAccount.insert(mergedAccount.end(), emails.begin(), emails.end());
            ans.push_back(mergedAccount);
        }
        return ans;
    }
};