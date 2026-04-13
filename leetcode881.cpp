/*
Problem: LeetCode 881 – Boats to Save People

Approach:
1. Sort the array of people based on weight.
2. Use two pointers:
   - i → lightest person
   - j → heaviest person
3. While i <= j:
   - If people[i] + people[j] ≤ limit:
       → pair them together (i++, j--)
   - Else:
       → heaviest person goes alone (j--)
   - In both cases → increment boat count
4. Continue until all people are assigned boats.
5. Return total boats used.

Time Complexity: O(N log N)
Space Complexity: O(1)
*/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n = people.size();
        int i= 0;
        int j = n - 1;
        int boats = 0;
        while(i < j || i == j){
            if(people[i] + people[j] <= limit){
                i++;
                j--;
                boats++;
            }else{
                j--;
                boats++;
            }
        }
        return boats;
    }
};
