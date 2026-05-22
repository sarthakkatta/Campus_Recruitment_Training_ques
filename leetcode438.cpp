/*
Problem: LeetCode 438 – Find All Anagrams in a String

Approach:
1. Two approaches are shown:
   - Brute Force
   - Optimized Sliding Window
2. Optimized Approach:
   - Store frequency of pattern characters in counter array.
3. Use sliding window of size k = p.length():
   - Decrease frequency for incoming character.
4. When window size becomes k:
   - Check if all frequencies are zero:
       → Current window is an anagram.
5. Before sliding window forward:
   - Restore frequency of outgoing character.
6. Store all starting indices of valid anagrams.

Key Idea:
- If frequency array becomes all zeros,
  both strings have same character frequencies.

Time Complexity: O(N * 26) ≈ O(N)
Space Complexity: O(26) ≈ O(1)
*/

// class Solution {
// public:

//     bool isanagram(int count[]) {
//         for(int i = 0; i < 26; i++) {
//             if(count[i] != 0) {
//                 return false;
//             }
//         }
//         return true;
//     }

//     vector<int> findAnagrams(string s, string p) {
//         vector<int> ans;
//         int n = s.size();
//         int m = p.size();
//         if(n < m) return ans;
//         for(int i = 0; i <= n - m; i++) {
//             int count[26] = {0};
//             for(int j = 0; j < m; j++) {
//                 count[s[i + j] - 'a']++;
//                 count[p[j] - 'a']--;
//             }
//             if(isanagram(count)) {
//                 ans.push_back(i);
//             }
//         }
//         return ans;
//     }
// };




class Solution {
public:
    bool allZero(vector<int>& counter) {
        for(int i = 0; i < 26; i++) {
            if(counter[i] != 0) {
                return false;
            }
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        vector<int> counter(26, 0);
        // Count frequency of pattern
        for(int i = 0; i < p.length(); i++) {
            char ch = p[i];
            counter[ch - 'a']++;
        }
        int i = 0, j = 0;
        int k = p.length();
        vector<int> result;
        while(j < n) {
            // remove current char from counter
            counter[s[j] - 'a']--;
            // window size reached
            if(j - i + 1 == k) {
                if(allZero(counter)) {
                    result.push_back(i);
                }
                // restore left character
                counter[s[i] - 'a']++;
                i++;
            }
            j++;
        }
        return result;
    }
};
