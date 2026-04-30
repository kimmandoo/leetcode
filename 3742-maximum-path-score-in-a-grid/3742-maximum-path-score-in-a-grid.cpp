class Solution {
public:
    int m, n;
    // [r][c][k]-(r, c) 위치에서 남은 비용이 k일 때 얻을 수 있는 최대 점수
    vector<vector<vector<int>>> memo; 
    
    // 유효하지 않은 경로를 나타내는 매우 작은 값
    const int INF = 1e9;

    int solve(int r, int c, int k, vector<vector<int>>& grid) {
        if (r >= m || c >= n) return -INF;

        int score = grid[r][c];
        int cost = (grid[r][c] > 0) ? 1 : 0;

        if (k < cost) return -INF;

        if (r == m - 1 && c == n - 1) {
            return score;
        }

        if (memo[r][c][k] != -2) return memo[r][c][k];

        // 오른쪽 또는 아래
        int right = solve(r, c + 1, k - cost, grid);
        int down = solve(r + 1, c, k - cost, grid);

        int res = max(right, down);

        // 만약 두 방향 모두 불가능한 경로라면 현재 상태도 -INF 저장
        if (res <= -INF) {
            return memo[r][c][k] = -INF;
        }

        return memo[r][c][k] = score + res;
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        memo.assign(m, vector<vector<int>>(n, vector<int>(k + 1, -2)));

        int result = solve(0, 0, k, grid);

        return (result < 0) ? -1 : result;
    }
};