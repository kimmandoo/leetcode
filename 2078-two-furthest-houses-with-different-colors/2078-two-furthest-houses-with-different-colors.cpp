class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int mx = -1;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(colors[i] != colors[j]){
                    mx = max(mx, abs(j-i));
                }
            }
        }
        return mx;
    }
};