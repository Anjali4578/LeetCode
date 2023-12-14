class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> diff(n, vector<int> (m, 0));
        vector<int> row(n), col(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                    row[i] += grid[i][j];
                    col[j] += grid[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                diff[i][j] = 2 * row[i] + 2 * col[j] - n - m;
            }
        }
        return diff;
    }
};