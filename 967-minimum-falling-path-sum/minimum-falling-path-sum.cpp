class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                matrix[i][j] += min({matrix[i + 1][max(j - 1, 0)],
                                     matrix[i + 1][j], 
                                     matrix[i + 1][min(j + 1, n - 1)]});
            }
        }
        return *min_element(matrix[0].begin(), matrix[0].end());
    }
};