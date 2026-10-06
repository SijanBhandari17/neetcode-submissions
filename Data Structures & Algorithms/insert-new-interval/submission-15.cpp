class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) {
            intervals.push_back(newInterval);
            return intervals;
        }
        int size = intervals.size();
        int j = 0, k = 0;
        int l = 0, r = size - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (intervals[mid][0] < newInterval[0]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (l == 0) {
            k = 0;
        } else {
            k = l - 1;
        }
        cout << k;
        cout << l;

        if (intervals[k][0] > newInterval[0]) {
            intervals.insert(intervals.begin() + k, newInterval);
        } 
        else if (intervals[k][1] < newInterval[0]) {
            intervals.insert(intervals.begin() + k + 1, newInterval);
            k++;
        } else {
            intervals[k][0] = min(newInterval[0], intervals[k][0]);
            intervals[k][1] = max(newInterval[1], intervals[k][1]);
        }
        cout << k + 1;
        size = intervals.size();
        for (int i = k + 1; i < size; i++) {
            if (intervals[k][1] >= intervals[i][0]) {
                intervals[k][1] = max(intervals[k][1], intervals[i][1]);
                if (j == 0) {
                    j = i;
                }
            } else {
                if (j != 0) {
                    intervals[j] = intervals[i];
                    j++;
                }
            }
        }

        while (j != 0 && j < size) {
            intervals.pop_back();
            j++;
        }

        return intervals;
    }
};
