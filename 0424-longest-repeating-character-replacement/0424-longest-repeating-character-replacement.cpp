class Solution {
public:
    int getMax(unordered_map<char,int> mp)
    {
        int Max = 0;
        for(auto &i : mp)
        {
            Max = max(Max,i.second);
        }
        return Max;
    }
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int n = s.size();
        int left = 0,right = 0;
        int Max_size = 0;
        while(right < n)
        {
            mp[s[right]]++;
            if((right - left + 1) - getMax(mp) > k)
            {
                mp[s[left]]--;
                left++;
            }
            Max_size = max(Max_size,right - left + 1);
            right++;
        }
        return Max_size;

    }
};