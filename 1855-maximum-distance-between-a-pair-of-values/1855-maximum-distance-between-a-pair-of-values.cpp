class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int i=0, j=0;
        int mx = -1;
        while(i<n && j <m){
            if(nums1[i] <= nums2[j]){
                mx = max(mx, j-i);
                j++; // j의 nums값이 더 작아질 수 있게
            } else{
                i++; // nums1 값이 작아지도록
                if(i>j){
                    j++;
                }
            }
        }
        if(mx == -1) return 0;
        return mx;
    }
};