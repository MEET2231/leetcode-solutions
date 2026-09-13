class Solution {
public:
    long long minOperations(vector<int>& nums) {

//Initialization part to precompute palindromic numbers till 1e9+1
//using static to preserve odd and even vector across test cases.
//using again bool so that program dosent recompute them.
        static vector<long long> odd , even;
        static bool first_time = true;
        if(first_time)
        {
            first_time = false;
            for(long long i = 1;i< 1e5;i++)
            {

                string s = to_string(i);
                int n = s.size();
                //direct mirror(even length) 123 -> 123321 
                string a = s;
                for(int j = n - 1;j >= 0;j--)
                {
                    a += s[j];
                }
                long long Num = stoll(a);//palindromic num
                if(Num <= 1e9 + 1)
                {
                    if(Num & 1)
                    {
                        odd.push_back(Num);
                    }
                    else
                    {
                        even.push_back(Num);
                    }
                }
                //mirror with a common middle (odd length) 123 ->12321
                string b = s;
                for(int j = n-2; j >= 0;j--)
                {
                    b += s[j];
                }
                Num = stoll(b);
                if(Num <= 1e9 + 1)
                {
                    if(Num & 1)
                    {
                        odd.push_back(Num);
                    }
                    else
                    {
                        even.push_back(Num);
                    }
                }
            }
            sort(odd.begin(),odd.end());
            sort(even.begin(),even.end());
        }
//now 
        long long ans = 0;
        for(long long x : nums)
        {
            const vector<long long>& a = (x & 1) ? odd : even;
            
            auto it = lower_bound(a.begin(),a.end(),x);
            long long d = LLONG_MAX;
            if(it != a.end())
            {
                d = min(d, abs(x - *it)/2);
            }
            if(it != a.begin())
            {
                --it;
                d = min(d, abs(x - *it)/2);
            }
            ans += d;

        }
        return ans;

    }
};