class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, r = n - 1;
        unordered_set<double> st;

        while (l < r) {
            double avg = (nums[l] + nums[r])/2.0;
            st.insert(avg);
            l++;
            r--;
        }

        return st.size();

        // T.C. = (N log N)
        // S.C. = O(N) if N distinct averages
    }
};