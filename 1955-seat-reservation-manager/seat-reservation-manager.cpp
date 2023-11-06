class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int cnt = 0;

    SeatManager(int n) {
        
    }
    
    int reserve() {
        int seatNo = pq.empty() ? ++cnt : pq.top();
        if (!pq.empty()) {
            pq.pop();
        }  

        return seatNo;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */