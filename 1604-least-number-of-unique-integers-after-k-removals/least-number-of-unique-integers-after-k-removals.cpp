class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int, int> mp;
        vector<int> freq;
        for (int i: arr) mp[i]++;
        for (auto p: mp) {
            freq.push_back(p.second);
        }
        sort (freq.begin(), freq.end());
        int cnt = 0;
        for (int i: freq) {
            if (k >= i) {
                k -= i;
                cnt++;
            }
            else break;
        }

        return freq.size() - cnt;
    }
};