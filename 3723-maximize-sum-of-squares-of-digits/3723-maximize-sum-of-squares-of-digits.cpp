class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > num*9)
        {
            return "";
        }
        string ans = "";
        for( int i =0;i<num;i++)
        {
            int d = min(9,sum);
            ans += '0' + d;
            sum -= d;
        }
        return sum == 0? ans:"0";
    }
};