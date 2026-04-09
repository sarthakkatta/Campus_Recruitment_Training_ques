/*
Problem: LeetCode 2124 – Check if All A's Appears Before All B's

Approach:
1. Traverse the string from index 1 to end.
2. Check adjacent characters:
   - If a 'b' is followed by an 'a', it violates the condition.
3. If such a case is found → return false.
4. If no violation is found → return true.

Key Idea:
- String should not contain "ba" as a substring.

Time Complexity: O(N)
Space Complexity: O(1)
*/

// class Solution {
// public:
//     bool checkString(string s) {
//         bool prevB = false; 
//         for(char c : s){
//             if(c == 'b') prevB = true;
//             else if(c == 'a' && prevB) return false;
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool checkString(string s) {
        for(int i = 1; i < s.size();i++){
            if(s[i - 1] == 'b' && s[i] == 'a') return false;
        }
        return true;
    }
};
