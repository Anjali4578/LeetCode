class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int, int> mp;
        for (auto it: grid) {
            for (int k: it) {
                mp[k]++;
            }
        }
        int a = -1, b = -1;
        int n = grid.size();
        for (int i = 1; i <= n * n; i++) {
            if (mp[i] == 2) a = i;
            if (mp[i] == 0) b = i;
        }

        return {a, b};

        // T.C. = O(n * n)   S.C. = O(n * n)
    }
};