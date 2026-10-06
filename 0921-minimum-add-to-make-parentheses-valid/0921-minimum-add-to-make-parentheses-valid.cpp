class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        int open = 0;
        int add = 0;

        for(int i = 0;i<n;i++)
        {
            if(s[i] == '(') open++;
            else
            {
                if(open > 0 ) open--;
                else
                {
                    add++;
                }
            }
        }
        return add + open;
        
    }
};