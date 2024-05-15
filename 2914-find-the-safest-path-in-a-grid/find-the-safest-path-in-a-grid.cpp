class Solution {
public:
    vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    void transform(vector<vector<int>>& grid) {

        int n = grid.size();
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    vis[i][j] = 0;
                }
            }
        }

        int level = 1;
        while (!q.empty()) {
            int k = q.size();
            while (k--) {
                auto it = q.front();
                q.pop();

                for (auto d: dir) {
                    int x = it.first + d.first;
                    int y = it.second + d.second;

                    if (x < 0 || x >= n || y < 0 || y >= n || vis[x][y] != -1) continue;

                    vis[x][y] = level;
                    q.push({x, y});
                }
            }
            level++;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = vis[i][j];
            }
        }
    }

    int solve(int n, vector<vector<int>>& grid) {

        vector<vector<int>> dis(n, vector<int>(n, 0));
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({grid[0][0], {0, 0}});

        dis[0][0] = grid[0][0];

        while (!pq.empty()) {

            auto it = pq.top();
            pq.pop();

            int cost = it.first;
            int x = it.second.first;
            int y = it.second.second;

            for (auto d: dir) {
                int nx = x + d.first;
                int ny = y + d.second;

                if (nx < 0 || nx >= n || ny < 0 || ny >= n || dis[nx][ny] >= min(cost, grid[nx][ny])) 
                {
                    continue;
                }

                dis[nx][ny] = min(cost, grid[nx][ny]);
                pq.push({dis[nx][ny], {nx, ny}});
            }
        }

        return dis[n - 1][n - 1];
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {

        transform(grid);
        int n = grid.size();

        return solve(n, grid);
    }
};