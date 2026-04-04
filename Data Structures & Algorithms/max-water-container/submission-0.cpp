class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int max = 0;
        int l =0;
        int r = n - 1;
        while(l < r){
            int area = min(heights[l],heights[r]) * (r - l);
            if(area > max) max = area;
            if(heights[l] < heights[r]) {l++;}
            else {r--;}
        }
        return max;
    }
};
