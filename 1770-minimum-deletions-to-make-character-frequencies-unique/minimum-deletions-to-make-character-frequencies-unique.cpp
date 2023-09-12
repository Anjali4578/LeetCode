class Solution {
public:
    int minDeletions(string s) {
        int ans = 0;
        unordered_map<char, int> mp;
        set<int> st;
        for (auto c: s) {
            mp[c]++;
        }

        for (auto it: mp) {
            while (st.find(it.second) != st.end()) {  
                // if the count is already present in the set we delete the character
                it.second--;
                ans++;
            }

            if (it.second > 0) {
                st.insert(it.second);
            } 
        }

        return ans; 
    }
};