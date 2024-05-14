class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> a(m, vector<int>(n));

        a[0][0] = grid[0][0];

        for (int i = 1; i < m; i++) {   // first column    // m
            a[i][0] = min(a[i - 1][0], grid[i][0]);
        }
        for (int i = 1; i < n; i++) {    // first row    // n
            a[0][i] = min(a[0][i - 1], grid[0][i]);
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                a[i][j] = min({a[i - 1][j], a[i][j - 1], grid[i][j]});
            }
        } // m * n

        int ans = INT_MIN;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                int mini = INT_MAX;
                if (i - 1 >= 0) {
                    mini = min(mini, a[i - 1][j]);
                }
                if (j - 1 >= 0) {
                    mini = min(mini, a[i][j - 1]);
                }

                ans = max(ans, grid[i][j] - mini);
            }
        }   // m * n

        return ans;

        // T.C. & S.C = O(m * n)
    }
};