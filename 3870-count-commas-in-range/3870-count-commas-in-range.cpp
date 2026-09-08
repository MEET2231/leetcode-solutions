class Solution {
public:
    int countCommas(int n) {
        long long start = 1000;
        int commas = 1;
        long long ans = 0;

        while(start <= n){
            long long end = min((long long)n, start * 1000 - 1);
            ans += (end - start + 1) * commas;

            start *= 1000;
            commas++;
        }

        return ans;
    }
};