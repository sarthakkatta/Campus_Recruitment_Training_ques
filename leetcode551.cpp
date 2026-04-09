/*
Problem: LeetCode 551 – Student Attendance Record I

Approach:
1. Initialize:
   - cntA → count of 'A' (absent days)
   - currL → current consecutive 'L' streak
   - maxcons → maximum consecutive 'L's
2. Traverse the string:
   - If 'A' → increment cntA
   - If 'L' → increment currL and update maxcons
   - Else → reset currL to 0
3. Check conditions:
   - cntA < 2 (at most one 'A')
   - maxcons < 3 (no 3 consecutive 'L')
4. Return true if both conditions satisfied.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    bool checkRecord(string s) {
        int cntA = 0, currL = 0, maxcons = 0;
        for(char c : s){
            if(c == 'A') cntA++;
            if(c == 'L'){
                currL++;
                maxcons = max(maxcons, currL);
            } else {
                currL = 0;
            }
        }
        return (cntA < 2 && maxcons < 3);
    }
};
