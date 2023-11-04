class Solution {
public:
    string frequencySort(string s) {
    /*    int cnt[128] = {};
        for (char c: s) {
            cnt[c] += 1;
        }

        sort (s.begin(), s.end(), [&](char a, char b) {
            return cnt[a] > cnt[b] || (cnt[a] == cnt[b] && a < b);
        });

        return s;  */

        // bucket sort

        int n = s.size();
        unordered_map<char, int> cnt;

        for (char c: s) {
            cnt[c]++;
        }

        vector<vector<char>> bucket(n + 1);
        for (auto [c, f]: cnt) {
            bucket[f].push_back(c);  // char with same frequency grouped together
        }

        string ans = "";
        for (int freq = n; freq >= 1; freq--) {
            for (char c: bucket[freq]) {
                ans.append(freq, c);
            }
        }

        return ans;
    }
};