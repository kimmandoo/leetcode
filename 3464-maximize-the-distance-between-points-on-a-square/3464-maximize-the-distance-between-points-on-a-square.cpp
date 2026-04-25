using ll = long long;

class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> list;
        for (auto& p : points) {
            ll x = p[0], y = p[1];
            if (y == 0) list.push_back(x);                         // 아래변
            else if (x == side) list.push_back(side + y);          // 오른쪽변
            else if (y == side) list.push_back(2LL * side + (side - x)); // 윗변
            else if (x == 0) list.push_back(3LL * side + (side - y));    // 왼쪽변
        }
        
        sort(list.begin(), list.end());
        int n = list.size();
        ll tot = 4LL * side;

        // 이분 탐색
        ll l = 1, r = tot / k; 
        ll ans = 0;

        while (l <= r) {
            ll mid = l + (r - l) / 2;
            if (canPlace(list, k, mid, tot)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return (int)ans;
    }

    bool canPlace(const vector<ll>& list, int k, ll mid, ll tot) {
        int n = list.size();
        
        for (int i = 0; i < n; i++) {
            if (list[i] > list[0] + mid) break; 

            int count = 1;
            ll lastPos = list[i];
            
            for (int j = i + 1; j < n; j++) {
                if (list[j] - lastPos >= mid) {
                    count++;
                    lastPos = list[j];
                    
                    if (count == k) {
                        if (tot - (lastPos - list[i]) >= mid) return true;
                        break; 
                    }
                }
            }
        }
        return false;
    }
};