class Solution {
public:
    set<vector<int>> s;

    void helper(vector<int>& candidates, int target, vector<int> &temp, int idx, int sum) {
        int n = candidates.size();
        if (sum > target) return;
        if (idx == n) {
            if (sum == target) {
                cout << "ja rha" << endl;
                s.insert(temp);
                return;
            }
            return;
        }

        helper(candidates, target, temp, idx + 1, sum);
        sum += candidates[idx];
        temp.push_back(candidates[idx]);
        helper(candidates, target, temp, idx, sum);
        temp.pop_back();
        sum -= candidates[idx];
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       // sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0;
        helper(candidates, target, temp, 0, 0);

        for (auto i: s) {
            ans.push_back(i);
        }

        return ans;
    }
};