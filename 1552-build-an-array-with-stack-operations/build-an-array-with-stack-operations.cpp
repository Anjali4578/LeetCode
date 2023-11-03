class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        unordered_set<int> s(target.begin(), target.end());

        for (int i = 1; i <= target.back(); i++) {
            if (s.find(i) != s.end()) {   // desired element push
                ans.push_back("Push");
            }
            else {
                ans.push_back("Push");   // undesired element push and pop out immediately
                ans.push_back("Pop");
            }
        }
        return ans;
        // T.C. = O(n)
        // S.C. = O(1)
    }
};