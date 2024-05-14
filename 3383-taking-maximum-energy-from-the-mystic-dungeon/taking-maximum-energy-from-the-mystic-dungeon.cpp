class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        // int n = energy.size();
        // vector<vector<int>> a(n + 1);

        // int index = 0;
        // for (int i = 0; i < n; i++) {  // O(n)
        //     a[index].push_back(energy[i]);
        //     index++;
        //     if (index == k) index = 0;
        // }

        // int ans = INT_MIN;
        // for (auto it: a) { // O(k)
        //     if (it.size() > 0) {
        //         int suffix_sum = 0;
        //         for (int i = it.size() - 1; i >= 0; i--) {  // O(n / k)
        //             suffix_sum += it[i];
        //             ans = max(ans, suffix_sum);
        //         }
        //     }
        // }

        // return ans;

        // T.C. = O(n)
        // S.C. = O(k * n / k) ~ O(n)

        int n = energy.size();
        vector<int> dp(n);

        int ans = INT_MIN;
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = energy[i] + (i + k < n ? dp[i + k] : 0);
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};