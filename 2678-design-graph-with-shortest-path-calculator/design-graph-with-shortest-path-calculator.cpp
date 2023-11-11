class Graph {
private:
    int dijkstra(int start, int end) {
        int n = adj.size();
        vector<int> dis(n, INT_MAX);
        dis[start] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start});

        while (!pq.empty()) {
            int node = pq.top().second;
            int cost = pq.top().first;
            pq.pop();

            if (node == end) return cost;
            if(cost > dis[node]) continue;

            for (auto edge: adj[node]) {
                int wt = edge.second;
                int adjNode = edge.first;

                if (cost + wt < dis[adjNode]) {
                    dis[adjNode] = cost + wt;
                    pq.push({dis[adjNode], adjNode});
                }
            }
        }

        return -1;
    }

public:
    vector<vector<pair<int, int>>> adj;
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for (auto edge: edges) {
            adj[edge[0]].emplace_back(edge[1], edge[2]);
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].emplace_back(edge[1], edge[2]);
    }
    
    int shortestPath(int node1, int node2) {
        return dijkstra(node1, node2);
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */