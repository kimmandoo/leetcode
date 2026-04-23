#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

#define ll long long // 세미콜론안붙인다

class Solution {
public:
    vector<ll> distance(vector<int>& nums) {
        int n = nums.size();
        // 각 숫자의 모든 인덱스와 총합을 미리 저장
        unordered_map<int, vector<int>> groups;
        unordered_map<int, ll> total_sum_map;
        
        for (int i = 0; i < n; ++i) {
            groups[nums[i]].push_back(i);
            total_sum_map[nums[i]] += i;
        }

        // 각 숫자가 몇 번째로 등장했는지 지금까지의 인덱스 합은 얼마인지 추적
        unordered_map<int, int> count_map;
        unordered_map<int, ll> prefix_sum_map;
        vector<ll> arr;

        for (int i = 0; i < n; ++i) {
            int val = nums[i];
            ll curIdx = i;
            
            ll total_sum = total_sum_map[val]; // 현재 값에 대한 인덱스 총합
            int total_count = groups[val].size(); // 현재 값이 몇개인지?
            ll prefix_sum = prefix_sum_map[val]; // 현재 값의 누적합(지금까지)
            int count_so_far = count_map[val]; // 현재 인덱스 이전의 그 값 개수

            ll left = (ll)count_so_far * curIdx - prefix_sum;
            
            ll right_sum = total_sum - (prefix_sum + curIdx);
            int right_count = total_count - 1 - count_so_far; // 오른쪽 개수
            ll right = right_sum - (ll)right_count * curIdx;

            arr.push_back(left + right);

            prefix_sum_map[val] += curIdx;
            count_map[val]++;
        }

        return arr;
    }
};