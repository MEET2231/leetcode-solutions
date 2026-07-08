class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        int n = wordList.size();
        int m = wordList[0].size();
        // existance check
        bool flag = false;
        for(int i = 0;i<n;i++)
        {
            if(wordList[i] == endWord) flag = true;
        }
        if(!flag) return 0;
        // Filling that map
        unordered_map<string,vector<string>> mp;
        wordList.push_back(endWord);
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                string temp = wordList[i];
                temp[j] = '*';
                mp[temp].push_back(wordList[i]);
            }
        }
        // ----------
        set<string> visited;
        visited.insert(beginWord);
        queue<string> q;
        q.push(beginWord);
        int count = 1;
        while(!q.empty())
        {
            int s = q.size();
            while(s--)
            {
                string word = q.front();q.pop();
                if(word == endWord) return count;
                for(int j = 0;j<m;j++)
                {
                    string temp = word;
                    temp[j] = '*';
                    for(auto &i : mp[temp])
                    {
                        if(visited.find(i) == visited.end())
                        {
                            q.push(i);
                            visited.insert(i);
                        }
                    }
                }
            }
            count++;
        }
        return 0;

    }
};