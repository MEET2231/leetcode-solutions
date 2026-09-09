class Solution {
public:
    int memo[105][105];

    bool check(int i, int count, string& s) {
        if (count < 0) {
            return false;
        }

        if (i == s.length()) {
            return count == 0;
        }

        if (memo[i][count] != -1) {
            return memo[i][count];
        }
        if (s[i] == '(') {
            return memo[i][count] = check(i + 1, count + 1, s);
        }

        if (s[i] == ')') {
            return memo[i][count] = check(i + 1, count - 1, s);
        }

        s[i] = '(';
        bool temp1 = check(i + 1, count + 1, s);

        s[i] = ')';
        bool temp2 = check(i + 1, count - 1, s);

        bool temp3 = check(i + 1, count, s);

        s[i] = '*';

        return memo[i][count] = (temp1 || temp2 || temp3);
    }

    bool checkValidString(string s) {
        memset(memo, -1, sizeof(memo));
        return check(0, 0, s);
    }
};