class Solution {
public:
    string minWindow(string s, string t) {
        int mini = INT_MAX;
        int start = -1;

        int hash[256] = {0};
        for (char c: t) hash[c]++;
        int cnt = 0;

        int l = 0, r = 0;

        while (r < s.size()) {
            if (hash[s[r]] > 0) {
                cnt++;
            }
            hash[s[r]]--;

            while(cnt == t.size()) {
                if (r - l + 1 < mini) {
                    mini = r - l + 1;
                    start = l;
                }

                hash[s[l]]++;
                if (hash[s[l]] > 0) {
                    cnt--;
                }
                l++;
            }
            r++;
        }

        return (start == -1) ? "" : s.substr(start, mini);

        // T.C. = O(2N + M), S.C. = O(256)
    }
};