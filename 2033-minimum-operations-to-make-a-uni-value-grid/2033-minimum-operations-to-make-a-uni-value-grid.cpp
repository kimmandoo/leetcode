class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        for (const auto& row : grid) {
            for (int val : row) {
                arr.push_back(val);
            }
        }
        int n = arr.size();
        int mod = arr[0] % x;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] % x != mod) {
                return -1;
            }
        }

        sort(arr.begin(), arr.end()); // 정렬하기

        int median = arr[arr.size() / 2];
        int ops = 0;

        for (int val : arr) {
            ops += abs(val - median) / x;
        }

        return ops;
    }
};