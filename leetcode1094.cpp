/*
Problem: LeetCode 1094 – Car Pooling

Approach:
1. Use Difference Array technique:
   - arr[i] represents change in passengers at location i.
2. For each trip:
   - Add passengers at pickup point → arr[from] += pass
   - Remove passengers at drop point → arr[to] -= pass
3. Traverse the array:
   - Maintain running sum of passengers in car.
   - If at any point sum > capacity → return false.
4. If capacity is never exceeded → return true.

Key Idea:
- Instead of simulating each trip, use prefix sum to track passengers efficiently.

Time Complexity: O(N + 1000)
Space Complexity: O(1000)
*/

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> arr(1001, 0);

        for(auto trip : trips){
            int pass =trip[0];
            int from =trip[1];
            int to =trip[2];

            arr[from] += pass;
            arr[to] -= pass;
        }

        int sum = 0;
        for(int i = 0; i < arr.size(); i++){
            sum += arr[i];
            if(sum > capacity) return false;
        }
        return true;
    }
};
