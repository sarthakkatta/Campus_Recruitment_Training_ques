/*
Problem: LeetCode 502 – IPO

Approach:
1. Combine capital and profit into pairs:
   - vec[i] = {capital[i], profits[i]}
2. Sort projects based on required capital.
3. Use a max-heap (priority queue) to store profits of feasible projects.
4. Iterate up to k times:
   - Add all projects whose capital ≤ current capital (w) into heap.
   - If heap is empty → break (no feasible projects).
   - Pick the project with maximum profit → add to w.
5. Return final capital w.

Key Idea:
- Always choose the most profitable project among those you can afford.

Time Complexity: O(N log N + K log N)
Space Complexity: O(N)
*/

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> vec(n);
        for(int i = 0; i < n;i++){
            vec[i] = {capital[i], profits[i]};
        }
        sort(vec.begin(),vec.end()); // by default sorted by captital ke hisaab se
        priority_queue<int> pq;
        int i = 0;
        while(k--){
            while(i < n && vec[i].first <= w){
                pq.push(vec[i].second);
                i++;
            }

            if(pq.empty()) break;

            w += pq.top();
            pq.pop();
        }
        return w;
    }
};
