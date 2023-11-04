class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mp;
            for (int j = i; j < n; j++) {
                mp[s[j]]++;

                int maxfreq = 0, leastfreq = INT_MAX;
                for (auto it: mp) {
                    maxfreq = max(maxfreq, it.second);
                    leastfreq = min(leastfreq, it.second); 
                }

                sum += (maxfreq - leastfreq);
            }
        }
        return sum;
    }
};