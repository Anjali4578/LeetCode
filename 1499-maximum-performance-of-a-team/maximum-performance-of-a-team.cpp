class Solution {
public:
    int MOD = 1e9 + 7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            v.emplace_back(efficiency[i], speed[i]);
        }

        sort(rbegin(v), rend(v));
        long long ans = 0;
        long long speed_sum = 0;

        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto [eff, sp]: v) {
            speed_sum += sp;
            pq.push(sp);

            if (pq.size() > k) {
                speed_sum -= pq.top();
                pq.pop();
            }

            ans = max(ans, speed_sum *  eff);
        }

        return ans % MOD;

    }
};