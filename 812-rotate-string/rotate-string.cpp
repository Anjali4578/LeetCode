class Solution {
public:
    bool rotateString(string s, string goal) {
 /*       if (s.size() != goal.size()) 
            return false;
        
        if (s == goal) return true;

        int len = goal.size();
        while (len--) {
            if (s == goal) return true;
            s = s.substr(1) + s[0];
             // substring from idex 1 to the last + first character
        }

        return false;  */

        return s.size() == goal.size() && (s + s).find(goal) != string::npos;
    }
};