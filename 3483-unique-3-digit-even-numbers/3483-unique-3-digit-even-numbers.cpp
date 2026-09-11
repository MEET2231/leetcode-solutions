class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for(int i = 0; i < digits.size(); i++) {
            freq[digits[i]]++;
        }
        
        int count = 0;
        
        for(int num = 100; num <= 998; num += 2) {
            int h = num / 100;         
            int t = (num / 10) % 10;   
            int u = num % 10;        
            
            freq[h]--;
            freq[t]--;
            freq[u]--;
            
            if(freq[h] >= 0 && freq[t] >= 0 && freq[u] >= 0) {
                count++;
            }
            
            freq[h]++;
            freq[t]++;
            freq[u]++;
        }
        
        return count;
    }
};