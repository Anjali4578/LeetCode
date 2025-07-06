class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<double> averages;
        double ans = INT_MAX;
        for (int i = 0; i < n / 2; i++) {
            double avg = (nums[i] + nums[n - i - 1]) / 2.0;
            averages.push_back(avg);
            ans = min(ans, avg);
        }

        return *min_element(averages.begin(), averages.end());

        // T.C. = O(n log n)
        // S.C. = O(m) -> for averages array
    }
};