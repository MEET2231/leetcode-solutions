class Solution {
public:
    
    string minWindow(string s, string t) {
        unordered_map<char,int> window;
        unordered_map<char,int> Tmp;
        unordered_set<char> Tset;
        int have = 0,need= 0;
        for(int i = 0;i<t.size();i++)
        {
            if(!Tmp[t[i]]) need++;
            Tmp[t[i]]++;
            Tset.insert(t[i]);
        }
        int left = 0, right = 0;
        int minLen = INT_MAX;
        int ansL = 0,ansR = 0;

        while(right < s.length() )
        {
            while(have != need && right < s.length())
            {
                window[s[right]]++;
                if(Tset.find(s[right]) != Tset.end())
                {
                    if(window[s[right]] == Tmp[s[right]])
                    {
                        have++;
                    } 
                }
                if(right < s.length())right++;
            }
            while(have == need)
            {
                if(right-left+1 < minLen)
                {
                    minLen = min(minLen,right-left+1);
                    ansL = left;
                    ansR = right;
                }

                window[s[left]]--;
                if(Tset.find(s[left]) != Tset.end())
                {
                    if(window[s[left]] < Tmp[s[left]])
                    {
                        have--;
                    }
                }
                left++;
            }
        }
        return s.substr(ansL,ansR-ansL);

    }
};