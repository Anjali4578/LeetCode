class Solution {
public:
    set<vector<int>> s;

    void helper(vector<int>& candidates, int target, int idx, vector<int> &temp) {
        int n = candidates.size();

        if (target < 0) return;
        if (idx == n) {
             if (target == 0) {
                s.insert(temp);
                return;
            }
            return;
        }

        temp.push_back(candidates[idx]);
        helper(candidates, target - candidates[idx], idx + 1, temp);
        temp.pop_back();

        while (idx < n - 1 && candidates[idx] == candidates[idx + 1]) idx++;
        helper(candidates, target, idx + 1, temp);

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        helper(candidates, target, 0, temp);
        for (auto i: s) {
            ans.push_back(i);
        }
        return ans;
    }
};