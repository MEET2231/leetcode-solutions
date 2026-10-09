class Solution {
public:
    string reverseVowels(string s) {
        int n = s.length();
        int i = 0 ;
        int j = n-1;
        unordered_set<char> glob = {'a','e','i','o','u','A','E','I','O','U'};
        while( i < j)
        {
            if(glob.find(s[i]) != glob.end() && glob.find(s[j]) != glob.end())
            {
                int temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                i++,j--;
            }
            else if(glob.find(s[i]) == glob.end() && glob.find(s[j]) != glob.end())
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return s;
        
    }
};