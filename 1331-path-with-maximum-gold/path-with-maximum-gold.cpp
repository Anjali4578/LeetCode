class Solution {
public:
    int dfs (vector<vector<int>>& grid, int i, int j) {
        
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || j < 0 || i >= m ||j >= n || grid[i][j] <= 0)
            return 0;
        
        grid[i][j] = -grid[i][j];

        int result = max({dfs(grid, i + 1, j), dfs(grid, i, j + 1), dfs(grid, i - 1, j), dfs(grid, i, j - 1)});

        grid[i][j] = -grid[i][j];

        return grid[i][j] + result;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dfs(grid, i, j));
            }
        }
        return ans;
    }
};