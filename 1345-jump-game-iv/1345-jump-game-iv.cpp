class Solution {
public:
    int minJumps(vector<int>& arr) {
        // 점프는 다음칸 점프, 이전칸 점프, 같은 칸 순간이동이 있음
        unordered_map<int, vector<int>> um;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            um[arr[i]].push_back(i);
        }
        vector<bool> vis(n, false); // 방문 인덱스 표시
        queue<int> q;
        
        // idx 0 부터 시작
        q.push(0);
        vis[0] = true;
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            
            // 현재 레벨에 있는 모든 노드를 처리
            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();
                if (curr == n - 1) return steps;
                if (curr + 1 < n && !vis[curr + 1]) {
                    vis[curr + 1] = true;
                    q.push(curr + 1);
                }

                if (curr - 1 >= 0 && !vis[curr - 1]) {
                    vis[curr - 1] = true;
                    q.push(curr - 1);
                }

                if (um.count(arr[curr])) { // 순간이동
                    for (int nxt : um[arr[curr]]) {
                        if (!vis[nxt]) {
                            vis[nxt] = true;
                            q.push(nxt);
                        }
                    }
                    um.erase(arr[curr]);
                }
            }
            steps++;
        }

        return -1;
    }
};