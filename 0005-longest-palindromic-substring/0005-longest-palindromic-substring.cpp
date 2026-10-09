class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n <= 1) return s;
        int maxLen = 0;
        int maxI=-1;
        for(int c =0;c<n;c++)
        {
            int curr_len = 0;
            int i = c;
            int j = c;
            while(i >= 0 && j <n && s[i] == s[j])
            {
                i--;
                j++;
            }
            curr_len = j - i - 1;
            if(curr_len > maxLen)
            {
                maxI = i + 1;
                maxLen = curr_len;
            }
            
            i = c;
            j = c + 1;
            while (i >= 0 && j < n && s[i] == s[j]) 
            {
                i--;
                j++;
            }
            curr_len = j - i -1;
            if(curr_len > maxLen)
            {
                maxI = i + 1;
                maxLen = curr_len;
            }

        }
        return s.substr(maxI,maxLen);
        
    }
};