class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        
        for (auto& w : walls) grid[w[0]][w[1]] = 1;
       
        for (auto& g : guards) grid[g[0]][g[1]] = 2;
        
      
        vector<pair<int, int>> dirs = {{0,-1},{0,1},{-1,0},{1,0}};
        
        for (auto& g : guards) {
            for (auto& d : dirs) {
                int x = g[0] + d.first;
                int y = g[1] + d.second;
                
                while (x >= 0 && x < m && y >= 0 && y < n && grid   [x][y] != 1 && grid[x][y] != 2) {
                    grid[x][y] = 3;  
                    x += d.first;
                    y += d.second;
                }
            }
        }
        
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) count++;
            }
        }
        return count;
    }
};
