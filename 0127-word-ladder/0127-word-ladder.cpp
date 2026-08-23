class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s;
        for(string& i : wordList)
        {
            s.insert(i);
        }
        if(s.find(endWord) == s.end()) return 0;

        queue<string> q;
        q.push(beginWord);
        int level = 1;
        while(!q.empty())
        {
            int n = q.size();
            for(int i =0;i<n;++i)
            {
                string front = q.front();q.pop();
                if(front == endWord) return level;
                for(int id=0;id<front.size();++id)
                {
                    char temp = front[id];
                    for(char a = 'a'; a <= 'z';++a)
                    {
                        front[id] = a;
                        if(s.find(front) != s.end())
                        {
                            q.push(front);
                            s.erase(front);
                        }
                    }
                    front[id] = temp;
                }
            }
            level++;

        }
        return 0;
        
    }
};