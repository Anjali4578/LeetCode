class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        
        int res = 0;
        unordered_map<string, int> mpp;

        for (auto w: words) {
            string s = w;
            reverse(s.begin(), s.end());

            if (mpp[s] > 0) {
                res++;   // if reverse string is present in map then increase ans by 1 and dec map of reversed string val by 1
                mpp[s]--;
            }
            else {
                mpp[w]++;   // if reverse string is not present increase map of original string val by 1
            }
        }

        return res;
    }
};