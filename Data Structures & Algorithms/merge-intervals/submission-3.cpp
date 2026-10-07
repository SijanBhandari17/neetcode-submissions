class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <=  1) return intervals;

        int size= intervals.size();
        int k = 0;int i = 1;
        int j = 0;
        sort(intervals.begin(),intervals.end());

        for(i; i < size;i++){
            if(intervals[k][1] >= intervals[i][0]){
                intervals[k][1] = max(intervals[k][1], intervals[i][1]);
                if(j == 0) j = i;
            }
            else{

                if(j != 0){
                    intervals[j] = intervals[i];
                    k = j;
                    j++;
                }else{
                    k++;
                }
            }
        }
        while(j != 0 && j < size){
            intervals.pop_back();
            j++;
        }
        return intervals;
    }
};
