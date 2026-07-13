class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string digits = "123456789";
        vector<int> result;
        
        int min_len = to_string(low).length();
        int max_len = to_string(high).length();
        
        for (int len = min_len; len <= max_len; ++len) {
            // i: 부분 문자열의 시작 인덱스 (9 - len 까지만 가능)
            for (int i = 0; i <= 9 - len; ++i) {
                // i번째부터 len개의 문자를 잘라내어 정수로 변환
                int num = stoi(digits.substr(i, len));
                
                // 조건에 맞으면 결과 배열에 추가
                if (num >= low && num <= high) {
                    result.push_back(num);
                }
            }
        }
        
        return result;
    }
};