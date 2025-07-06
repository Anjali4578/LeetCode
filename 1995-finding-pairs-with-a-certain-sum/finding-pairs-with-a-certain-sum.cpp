class FindSumPairs {
private:
    vector<int> n1, n2;
    unordered_map<int, int> mp;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->n1 = nums1;
        this->n2 = nums2;
        for (int i:n2) {
            mp[i]++;
        }
    }
    
    void add(int index, int val) {
        mp[n2[index]]--;
        n2[index] += val;
        mp[n2[index]]++;
        // O(1)
    }
    
    int count(int tot) {
        int cnt = 0;
        for (int i = 0; i < n1.size(); i++) {
            int rem = tot - n1[i];
            cnt += mp[rem];
        }
        // O(n)
        return cnt;
    }
    // T.C. = O(n + m + q1 (for q1 add calls) + q2.n (for q2 count calls) )
            // O(n + m) -> for storing 2 arrays
    // S.C. = O(n + m)  - 2 arrays
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */