class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int counter = 0;
        for (char c: s) {
            if (c == '(') {
                if (counter > 0) {
                    ans += c;     // not the first opening bracket of valid string
                }
                counter++;
            }
            else {
                if (counter > 1) {  
                    // there was more than one opening parenthesis within the current outermost pair
                    ans += c;
                }
                counter--;
            }
        }
        return ans;
    }
};