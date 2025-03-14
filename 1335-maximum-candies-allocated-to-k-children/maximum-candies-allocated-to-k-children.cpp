class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long int l = 1, h = 1e7;
        long long int ans = 0;
        while (l <= h) {
            long long int mid = (l + h) / 2;

            long long int cnt = 0;
            for (int i: candies) {
                cnt += (i / mid);
            }

            if (cnt >= k) {
                ans = mid;
                l = mid + 1;
            }
            else {
                h = mid - 1;
            }
        }
        return ans;
    }
};