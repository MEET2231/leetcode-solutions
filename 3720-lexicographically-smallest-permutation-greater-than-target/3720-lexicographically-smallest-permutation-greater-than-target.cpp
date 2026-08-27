class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = target.length();
        vector<int> mp(26,0);
        string ans = "";

        for(int i = 0;i<n;i++)
        {
            mp[s[i] - 'a']++;
        }
        int temp = -1;
        for(int i = 0;i<n;i++)
        {
            int x = target[i] - 'a';
            bool flag = false;
            if(mp[x] > 0)
            {
                mp[x]--;
                ans += x + 'a';
            }
            else
            {
                for(int  c = x+1;c<26;++c)
                {
                    if(mp[c] > 0)
                    {
                        ans += c + 'a';
                        mp[c]--;
                        temp = i;
                        flag = true;
                        break;
                    }
                }
                break;
            }
        }
        if(temp != -1)
        {
            for(int i=0;i<26;i++)
            {
                ans.append(mp[i],char(i + 'a'));
            }
            return ans;
        }
        else
        {
            for(int i = ans.length() - 1;i >= 0;i--)
            {
                mp[ans[i] - 'a']++;
                ans.pop_back();
                int x = target[i] - 'a';
                for(int c = x+1;c<26;c++)
                {
                    if(mp[c] > 0)
                    {
                        ans += c + 'a';
                        mp[c]--;
                        for(int j=0;j<26;j++)
                        {
                            ans.append(mp[j],char(j + 'a'));
                        }
                        return ans;
                    }
                }
                
            }
        }
        return "";
        
    }
};