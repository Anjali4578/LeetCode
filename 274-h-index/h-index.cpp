class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.rbegin(), citations.rend());

        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (citations[mid] >= mid + 1) l = mid + 1;
            else r = mid - 1;
        } 
        return l;

        // T.C. = O( N log N) 
        // S.C. = O (1)
    }
};