class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        vector<int> heights(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    heights[j] = 0;
                }
                else {
                    heights[j] += 1;
                }
            }

            vector<int> temp = heights;
            sort(temp.begin(), temp.end());

            for (int j = 0; j < n; j++) {
                ans = max(ans, temp[j] * (n - j));
            }
        }
        return ans;
    }
};