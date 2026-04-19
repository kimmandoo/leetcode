class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size(); // 배열의 길이를 미리 저장
        
        // 결과 벡터의 크기를 2 * n으로 미리 지정
        vector<int> res(2 * n); 
        
        for(int i = 0; i < n; i++) {
            res[i] = nums[i];       // 앞부분 채우기
            res[i + n] = nums[i];   // 뒷부분 채우기
        }
        
        return res;
    }
};