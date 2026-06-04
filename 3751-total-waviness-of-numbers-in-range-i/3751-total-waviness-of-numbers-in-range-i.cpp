#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    string target;
    long long total_waviness_sum;

    void dfs(int idx, int prev, int pprev, bool is_less, bool is_started, int current_waviness) {
        if (idx == target.length()) {
            if (is_started) {
                total_waviness_sum += current_waviness;
            }
            return;
        }

        int limit = is_less ? 9 : (target[idx] - '0');

        for (int d = 0; d <= limit; ++d) {
            bool next_less = is_less || (d < limit);
            bool next_started = is_started || (d > 0);

            if (next_started) {
                int bonus = 0;
                if (is_started && prev != 10 && pprev != 10) {
                    if (pprev < prev && prev > d) bonus = 1; // 피크
                    if (pprev > prev && prev < d) bonus = 1; // 밸리
                }

                dfs(idx + 1, d, prev, next_less, true, current_waviness + bonus);
            } else {
                dfs(idx + 1, 10, 10, next_less, false, 0);
            }
        }
    }

    long long getWavinessSum(int X) {
        if (X < 100) return 0;
        
        target = to_string(X);
        total_waviness_sum = 0;
        
        dfs(0, 10, 10, false, false, 0);
        
        return total_waviness_sum;
    }

    int countSingleWaviness(int X) {
        string s = to_string(X);
        if (s.length() < 3) return 0;
        int cnt = 0;
        for (int i = 1; i < s.length() - 1; ++i) {
            if (s[i-1] < s[i] && s[i] > s[i+1]) cnt++;
            if (s[i-1] > s[i] && s[i] < s[i+1]) cnt++;
        }
        return cnt;
    }

public:
    int totalWaviness(int num1, int num2) {
        long long result = getWavinessSum(num2) - getWavinessSum(num1) + countSingleWaviness(num1);
        return static_cast<int>(result);
    }
};