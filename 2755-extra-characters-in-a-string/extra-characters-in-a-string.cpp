class Solution {
public:
    int helper(int i, string &s, vector<string>& dictionary, vector<int>& dp) {
        int n = s.size();
        if (i == n) return 0;

        if (dp[i] != -1) return dp[i];

        int ans = n;

        for (string& word: dictionary) {
            int len = word.size();

            if (i + len <= s.size() && s.substr(i, len) == word) {
                int extra = helper(i + len, s, dictionary, dp);
                ans = min(ans, extra);
            }
        }

        int noWord = 1 + helper(i + 1, s, dictionary, dp);
        ans = min(ans, noWord);

        return dp[i] = ans;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<int> dp(n, -1);

        return helper(0, s, dictionary, dp);
    }
};