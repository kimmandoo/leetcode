class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n = queries[0].size();
        // nxm
        vector<string> res;
        for(const auto& q : queries){
            for(const auto& d: dictionary){
                int cnt = 0;
                // 각 알파벳이 얼마나 차이나는지?
                for(int i=0; i<n; i++){
                    if(q[i] != d[i]) cnt++;
                }
                if(cnt <= 2) {
                    res.push_back(q);
                    break;
                }
            }
        }
        return res;
    }
};