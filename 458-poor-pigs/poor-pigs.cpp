class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int total_trials = (minutesToTest / minutesToDie) + 1;
        int ans = (int)ceil(log2(buckets) / log2(total_trials));
        return ans;
    }
};