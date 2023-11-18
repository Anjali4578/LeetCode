class Solution {
public:
    unordered_map<string ,int> mp;

    int getMinInValid(string s) {
        stack<char> st;
        int i = 0;
        while (i < s.size()) {
            if (s[i] == '(') {
                st.push('(');
            }
            else if (s[i] == ')') {
                if (st.size() > 0 && st.top() == '(') {
                    st.pop();
                }
                else {
                    st.push(')');
                }
            }
            i++;
        }
        return st.size();
    }

    void solve(string s, int minInvalid, vector<string> &ans) {
        if (mp[s] != 0) return;
        else mp[s]++;
        
        if (minInvalid < 0) return;

        if (minInvalid == 0) {
            if (!getMinInValid(s)) {
                ans.push_back(s);
            }
            return;
        }

        for (int i = 0; i < s.size(); i++) {
            string left = s.substr(0, i);
            string right = s.substr(i + 1);
            solve(left + right, minInvalid - 1, ans);
        }

        return;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        solve(s, getMinInValid(s), ans);

        return ans;
    }
};