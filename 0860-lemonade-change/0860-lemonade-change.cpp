class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> bnk(3,0);
        bool flag = true; 
        for(int i : bills)
        {
            if(i == 5) bnk[0]++;
            else if(i == 10){
                if(bnk[0] >= 1)
                {
                    bnk[0]--;
                    bnk[1]++;
                }
                else 
                {
                    return false;
                }

            }
            else if(i == 20)
            {
                if((bnk[1] >= 1 && bnk[0] >= 1))
                {
                    bnk[1]--;
                    bnk[0]--;
                    bnk[2]++;
                    continue;
                }
                else if(bnk[0] >= 3)
                {
                    bnk[0] -= 3;
                    bnk[2]++;
                    continue;
                }
                return false;
            }
        }
        return true;
        
    }
};