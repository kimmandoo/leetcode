class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        deque<int> front;
        deque<int> back;
        int cnt = 0;
        
        for(const auto& cur: nums){
            if(cur == pivot){
                cnt++;
            } else if(cur < pivot){
                front.push_back(cur);
            } else {
                back.push_back(cur);
            }
        }

        vector<int> res;
        // 1. pivot보다 작은 값들 삽입
        for(const auto& c: front){
            res.push_back(c);
        }
        // 2. pivot과 같은 값들 삽입
        for(int i=0; i<cnt; i++){
            res.push_back(pivot);
        }
        // 3. pivot보다 큰 값들 삽입 (reverse 제거)
        for(const auto& c: back){
            res.push_back(c);
        }
        return res;
    }
};