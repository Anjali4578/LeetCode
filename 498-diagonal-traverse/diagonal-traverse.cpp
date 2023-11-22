class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> ans;
        map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                mp[i + j].push_back(mat[i][j]);
            }
        }

        for (auto it: mp) {
            if (it.first % 2 == 0) {
                reverse(it.second.begin(), it.second.end());
            }

            for (auto x: it.second) {
                ans.push_back(x);
            }
        }

        return ans;
    }
};