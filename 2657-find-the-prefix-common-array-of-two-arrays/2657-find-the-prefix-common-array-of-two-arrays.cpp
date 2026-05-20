class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> res(n);
        vector<int> freq(n + 1, 0);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            freq[A[i]]++;
            if (freq[A[i]] == 2) cnt++; // 이미 나왔던 숫자라면 공통 카운트 증가

            freq[B[i]]++;
            if (freq[B[i]] == 2) cnt++;

            res[i] = cnt;
        }

        return res;
    }
};