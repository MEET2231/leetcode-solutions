class Solution {
public:

    string lax_check(string& a,string b)
    {
        int len1 = a.length();
        int len2 = b.length();
        int MIN = min(len1,len2);
        for(int i = 0;i<MIN;++i)
        {
            if(a[i] == b[i]) continue;
            if(a[i] < b[i]) return a;
            else return b;
        }
        return a;
    }
    string shortestBeautifulSubstring(string s, int k) {
        
        int l = 0,r = 0;
        int count = 0;
        if(s[0] == '1') count++;
        int MIN = INT_MAX;
        int n = s.length();
        string ans = "";
        while(r < n)
        {
            if(count < k)
            {
                while(count != k && r<n)
                {
                    r++;
                    if(s[r] == '1') count++;
                }
            }
            if(count == k)
            {
                // update ans
                int len = r-l+1;
                if(len < MIN)
                {
                    MIN = len;
                    ans = s.substr(l,r-l+1);
                }
                else if(len == MIN)
                {
                    ans = lax_check(ans,s.substr(l,r-l+1));
                }
            }
            if(s[l] == '1')
            {
                count--;
                l++;
            }
            while(s[l] != '1' && l < r)
            {
                l++;
            }
        }
        return ans;

    }
};