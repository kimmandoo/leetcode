class Solution {
public:
    int di[4] = {-1, 0, 1, 0};
    int dj[4] = {0, 1, 0, -1};
    int n, m;
    
    vector<vector<bool>> visited;

    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        visited.assign(n, vector<bool>(m, false)); // Arrays.fill이랑 똑같음

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j]) {
                    if (go(i, j, -1, -1, grid[i][j], grid)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool go(int i, int j, int pi, int pj, char color, vector<vector<char>>& grid) {
        visited[i][j] = true;

        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];

            if (isValid(ni, nj, color, grid)) {
                // 만약 다음 칸이 이미 방문한 곳인데, 직전 칸이 아니면
                if (visited[ni][nj]) {
                    if (ni != pi || nj != pj) {
                        return true;
                    }
                } else {
                    if (go(ni, nj, i, j, color, grid)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool isValid(int ni, int nj, char c, vector<vector<char>>& grid) {
        return ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == c;
    }
};