class Solution {
private:
    // Helper function is faster than constructing an unordered_set
    bool isVowel(char c) {
        c = tolower(c); // Convert to lowercase to check fewer conditions
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    string reverseVowels(string s) {
        int n = s.length();
        int i = 0;
        int j = n - 1;
        
        while (i < j) {
            bool i_is_vowel = isVowel(s[i]);
            bool j_is_vowel = isVowel(s[j]);
            
            // Step 1: Both are vowels, swap and move both pointers
            if (i_is_vowel && j_is_vowel) {
                swap(s[i], s[j]);
                i++;
                j--;
            } 
            // Step 2: Left is not a vowel, move left pointer
            else if (!i_is_vowel) {
                i++;
            } 
            // Step 3: Right is not a vowel, move right pointer
            else {
                j--;
            }
        }
        
        return s;
    }
};