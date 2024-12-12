class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long sum = 0;
        priority_queue<int> pq;
        
        for (auto i: gifts){
            pq.push(i);
        }
       
        while (k-- && !pq.empty())
        {
            long long temp = pq.top();
            pq.pop();
            pq.push(floor(sqrt(temp)));  
        }
        
        while (!pq.empty())
        {
            long long x = pq.top();
            pq.pop();
            sum += x;
        }
            
        return sum;
    }
};