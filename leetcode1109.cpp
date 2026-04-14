/*
Problem: LeetCode 1109 – Corporate Flight Bookings

Approach:
1. Use Difference Array technique:
   - arr[i] represents change in seats at index i.
2. For each booking:
   - Add seats at starting index → arr[first - 1] += seats
   - Subtract seats after ending index → arr[last] -= seats
3. Compute prefix sum:
   - Running sum gives total seats booked for each flight.
4. Store results in res array and return.

Key Idea:
- Efficiently handle range updates using prefix sum instead of updating each index individually.

Time Complexity: O(N + bookings)
Space Complexity: O(N)
*/

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> arr(n + 1, 0);
        vector<int> res(n);

        for(auto book : bookings){
            int first =book[0];
            int last = book[1];
            int seats = book[2];

            arr[first - 1] += seats;
            arr[last] -= seats;
        }

        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            res[i] = sum;
        }
        return res;
    }
};
