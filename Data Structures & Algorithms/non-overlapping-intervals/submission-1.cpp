class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int o = 0;
        int k = 0;
        int m = 1;
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),[](const vector<int> &a, const vector<int> &b){
            return a[1] < b[1];
        });
        cout << n;
        while(m < n){
            if (intervals[m][0] >= intervals[k][1]){
                o++;
                k = m;
            } 
            m++;
        }
        return n - o - 1;
    }
};
