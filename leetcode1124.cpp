/*
Problem: LeetCode 1124 – Longest Well-Performing Interval

Approach:
1. Convert hours into score:
   - If hours[i] > 8 → +1 (tiring day)
   - Else → -1 (non-tiring day)
2. Maintain prefix sum:
   - prefixsum > 0 → entire range [0..i] is valid
3. Use hashmap to store first occurrence of each prefix sum.
4. For each index:
   - If prefixsum > 0 → update ans = i + 1
   - Else:
       → Check if (prefixsum - 1) exists in map
       → If yes, a valid subarray exists → update length
5. Store prefixsum in map only if not already present (to keep earliest index).
6. Return maximum length found.

Key Insight:
- We need prefixsum(j) - prefixsum(i) > 0
- So we search for prefixsum - 1 to maximize subarray length.

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        unordered_map<int,int> mp;
        int prefixsum = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(hours[i] > 8) prefixsum += 1;
            else prefixsum -= 1;

            if(prefixsum > 0) {
                ans = i + 1;
            }
            else{
                if(mp.count(prefixsum - 1)){
                    ans = max(ans , i - mp[prefixsum - 1]);
                }
            }
            if(!mp.count(prefixsum)){
                mp[prefixsum] = i;
            }
        }
        return ans;
    }
};
