class Solution {
public:
    typedef long long ll;
    long long countCommas(long long n) {
        ll num = n;
        ll start = 1000;
        ll commas = 1;
        ll ans =0;
        while(start <=num)
            {
                ll end = min(num,start*1000-1);
                ans += (end-start+1)*commas;
                start *= 1000;
                commas++;
            }
        return ans;
        
        
    }
};