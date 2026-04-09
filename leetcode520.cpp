/*
Problem: LeetCode 520 – Detect Capital

Approach:
1. Count number of uppercase letters in the word.
2. Valid cases:
   - All letters are uppercase (cnt == word.size())
   - All letters are lowercase (cnt == 0)
   - Only first letter is uppercase (cnt == 1 and first char is uppercase)
3. Return true if any valid condition is satisfied, else false.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt = 0;
        for(char c : word){
            if(isupper(c)) cnt++;
        }
        if(cnt == word.size()) return true;  
        if(cnt == 0) return true;            
        if(cnt == 1 && isupper(word[0])) return true; 
        return false;
    }
};
