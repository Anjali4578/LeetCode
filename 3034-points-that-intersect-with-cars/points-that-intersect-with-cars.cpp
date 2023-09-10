class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        unordered_set<int> s;
        for (auto i: nums) {
            int start = i[0], end = i[1];
            for (int i = start; i <= end; i++) {
              //  cout << i << " ";
                s.insert(i);
            }
           // cout << endl;
        }
        return s.size();
    }
};