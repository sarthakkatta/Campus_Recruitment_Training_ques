/*
Problem: LeetCode 1293 – Shortest Path in a Grid with Obstacles Elimination

Approach:
1. Use BFS since we need shortest path in an unweighted grid.
2. State representation:
   - (i, j, remaining_k) → position + remaining obstacle eliminations.
3. Start from (0,0,k).
4. Maintain a 3D visited array:
   - visited[i][j][k] → whether cell (i,j) is visited with k eliminations left.
5. For each step:
   - Explore 4 directions (up, down, left, right).
6. Conditions:
   - If next cell is empty (0) → move normally.
   - If next cell is obstacle (1) → move only if k > 0, reduce k.
7. If destination (m-1, n-1) is reached → return steps.
8. If BFS completes without reaching → return -1.

Key Idea:
- Same cell can be revisited with different remaining k values.
- Hence, 3D visited is required.

Time Complexity: O(m * n * k)
Space Complexity: O(m * n * k)
*/

class Solution {
public:
    vector<vector<int>> directions{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        queue<vector<int>> que;
        
        int i = 0, j = 0;
        que.push({i, j, k});
        
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(k + 1, false)));
        int steps = 0;
        while(!que.empty()) {
            int size = que.size();
            while(size--) {
                vector<int> temp = que.front();
                que.pop();
                int curr_i   = temp[0];
                int curr_j   = temp[1];
                int obs = temp[2];
                
                if(curr_i == m-1 && curr_j == n-1)
                    return steps;
                
                for(vector<int> &dir : directions) {
                    int new_i = curr_i + dir[0];
                    int new_j = curr_j + dir[1];
                    
                    if(new_i < 0 || new_i >= m || new_j < 0 || new_j >= n)
                        continue;
                    
                    if(grid[new_i][new_j] == 0 && !visited[new_i][new_j][obs]) {
                        que.push({new_i, new_j, obs});
                        visited[new_i][new_j][obs] = true;
                    } else if(grid[new_i][new_j] == 1 && obs > 0 && !visited[new_i][new_j][obs-1]) {
                        que.push({new_i, new_j, obs-1});
                        visited[new_i][new_j][obs-1] = true;
                    }
                }
                
            }
            steps++;
        }
        return -1;
    }
};
