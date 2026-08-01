class Solution {
public:
    bool isPalindrome(string & s,int left,int right)
    {
        while(left < right)
        {
            if(s[left++] == s[right--]) continue;
            else return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.length();
        int i = 0,j = n-1;
        int mafi = 1;
        while(i < j)
        {
            if(s[i] != s[j])
            {
                return (isPalindrome(s,i+1,j) || isPalindrome(s,i,j-1));
            }
            i++;
            j--;
        }
        return true;
        
    }
};