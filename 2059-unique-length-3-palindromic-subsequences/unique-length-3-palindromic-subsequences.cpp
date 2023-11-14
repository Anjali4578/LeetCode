class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        unordered_map<int, pair<int, int>> mp;
        for (char c = 'a'; c <= 'z'; c++) {
            mp[c] = {-1, -1};
        }

        for (int i = 0; i < n; i++) {
            if (mp[s[i]].first == -1) {
                mp[s[i]].first = i;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if (mp[s[i]].second == -1) {
                mp[s[i]].second = i;
            }
        }

        int ans = 0;
        for (auto it: mp) {
            char ch = it.first;
            int l = it.second.first;
            int r = it.second.second;

            unordered_set<char> st;
            for (int i = l + 1; i < r; i++) {
                st.insert(s[i]);
            }

            ans += st.size();
        }

        return ans;
    }
};