/*
Problem: Minimum Operations to Make Array Equal to Target (Custom)

Approach:
1. Compute difference array:
   - diff[i] = target[i] - nums[i]
   - Represents required change at each index.
2. Initialize answer with absolute value of first element:
   - ans += |diff[0]|
3. Traverse from i = 1 to n-1:
   - If diff[i] and diff[i-1] have same sign:
       → Only add extra operations needed:
         max(0, |diff[i]| - |diff[i-1]|)
   - Else (sign changes):
       → Add full |diff[i]| since operations reset.
4. Return total operations.

Key Insight:
- Continuous segments with same sign can share operations.
- Sign change breaks continuity → requires fresh operations.

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        vector<long long> diff(n);
        for(int i = 0; i < n; i++){
            diff[i] = target[i] - nums[i];
        }
        long long ans = 0;
        ans += abs(diff[0]);
        for(int i = 1; i < n; i++){
            if((diff[i] >= 0 && diff[i-1] >= 0) || 
               (diff[i] <= 0 && diff[i-1] <= 0)) {
                ans += max(0LL, abs(diff[i]) - abs(diff[i-1]));
            }
            else {
                ans += abs(diff[i]);
            }
        }
        return ans;
    }
};
