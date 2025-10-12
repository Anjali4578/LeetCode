class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 1;  // onec character will from a balanced susbstring
        for (int l = 0; l < n; l++) {
            vector<int> freq(26, 0);
            freq[s[l] - 'a']++;
            for (int r = l + 1; r < n; r++) {
                freq[s[r] - 'a']++;
                bool check = true;
                for (auto it: freq) {
                    if (it > 0 && it != freq[s[l] - 'a']) {
                        check = false;
                    }
                }
                if (check) {
                    ans = max(ans, r - l + 1);
                }
            }
        }
        return ans;
        // T.C. = O(n^ 2 * 26)
        // S.C. = O(26)
    }
};