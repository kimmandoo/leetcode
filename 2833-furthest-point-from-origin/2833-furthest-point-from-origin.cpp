class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l = 0, r = 0;
        int n = moves.size();
        for(auto c: moves){
            if(c == 'L'){
                l++;
            }else if(c == 'R'){
                r++;
            }
        }
        int o = n - (l+r);
        return abs(l-r) + o;
    }
};