ass Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty() || rooms[0].empty()) return;
        int n = rooms.size(), m = rooms[0].size();
        queue<pair<int, int>> que;
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (rooms[i][j] == 0) {
                    ++cnt1;
                    que.push({i, j});
                }
            }
        }
        const int dx[4] = {0, 1, 0, -1};
        const int dy[4] = {1, 0, -1, 0};
        while (!que.empty()) {
            cnt2 = 0;
            for (int i = 0; i < cnt1; ++i) {
                auto u = que.front();
                que.pop();
                int x = u.first, y = u.second;
                for (int j = 0; j < 4; ++j) {
                    int xx = x + dx[j], yy = y + dy[j];
                    if (xx >= 0 && xx < n && yy >= 0 && yy < m && rooms[xx][yy] > rooms[x][y]) {
                        ++cnt2;
                        rooms[xx][yy] = rooms[x][y] + 1;
                        que.push({xx, yy});
                    }
                }
            }
            cnt1 = cnt2;
        }
    }
};
