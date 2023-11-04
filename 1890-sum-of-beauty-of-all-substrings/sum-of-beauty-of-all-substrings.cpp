class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int sum = 0;

 /*       for (int i = 0; i < n; i++) {
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
            mp.clear();
        }
        return sum;

        // T.C. = O (n 6 2 * 26) 
    */

        for (int i = 0; i < n; i++) {
            map<char, int> mp;
            multiset<int> st;

            for (int j = i; j < n; j++) {
                if (mp.find(s[j]) != mp.end()) {
                    st.erase(st.find(mp[s[j]]));
                }

                mp[s[j]]++;

                st.insert(mp[s[j]]);
                sum += (*st.rbegin() - *st.begin());
            }
        }

        // T.C. = O(n * nlog n)

        return sum;
    }
};