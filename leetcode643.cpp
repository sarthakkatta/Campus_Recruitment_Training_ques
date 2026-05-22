/*
Problem: LeetCode 643 – Maximum Average Subarray I

Approach:
1. Use Sliding Window of size k.
2. Maintain:
   - sum → current window sum
   - l → left pointer
   - r → right pointer
3. Expand window by adding nums[r].
4. When window size becomes k:
   - Compute average = sum / k
   - Update maximum average.
5. Slide window:
   - Remove nums[l] from sum
   - Move left pointer forward.
6. Return maximum average found.

Key Idea:
- Sliding window avoids recomputing sum for every subarray.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = INT_MIN;
        double sum = 0;
        int l = 0, r = 0;
        while(r< nums.size()){
            sum += nums[r];
            if((r-l+1) == k){
                ans = (sum/k)>ans ? (sum/k) : ans;
                sum-=nums[l];
                l++;
            }
            r++;
        }
        return ans;
    }
};
