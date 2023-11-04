class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string prefix = strs[0];
        for (string s: strs) {
            while (s.find(prefix) != 0) {   
                // if prefix string is not found at the index 0 i.e at the beginning
                prefix = prefix.substr(0, prefix.size() - 1);
            }
        }
        return prefix;
    }
};