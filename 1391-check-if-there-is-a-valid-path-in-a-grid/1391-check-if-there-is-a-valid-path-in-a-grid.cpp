class Solution {
    vector<vector<pair<int, int>>> directions = {
        {}, 
        {{0, -1}, {0, 1}},  // 1 좌, 우
        {{-1, 0}, {1, 0}},  // 2 상, 하
        {{0, -1}, {1, 0}},  // 3 좌, 하
        {{0, 1}, {1, 0}},   // 4 우, 하
        {{0, -1}, {-1, 0}}, // 5 좌, 상
        {{0, 1}, {-1, 0}}   // 6 우, 상
    };

public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            if (i == m - 1 && j == n - 1) return true;

            int type = grid[i][j];
            for (auto& dir : directions[type]) {
                int di = dir.first;
                int dj = dir.second;
                
                int ni = i + di;
                int nj = j + dj;

                if (ni >= 0 && ni < m && nj >= 0 && nj < n && !visited[ni][nj]) {
                    int nxt = grid[ni][nj];
                    bool connect = false;

                    for (auto& nextDir : directions[nxt]) {
                        // 다음 칸에서 지금 내 위치로 올수있나???
                        if (ni + nextDir.first == i && nj + nextDir.second == j) {
                            connect = true;
                            break;
                        }
                    }

                    if (connect) {
                        visited[ni][nj] = true;
                        q.push({ni, nj});
                    }
                }
            }
        }

        return false;
    }
};