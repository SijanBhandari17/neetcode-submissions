class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [](const vector<int> &a,const vector<int> &b){
            return a[1] < b[1];
        });
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;

        int n = trips.size();
        int curr_weight = 0;

        for(int i = 0; i < n; i++){
                while(!heap.empty() && heap.top().first <= trips[i][1]){
                    curr_weight -= heap.top().second;
                    heap.pop();
                }
            if(curr_weight + trips[i][0] <= capacity){
                curr_weight += trips[i][0];
                heap.push({trips[i][2],trips[i][0]});
            }
            else{
                return false;
            }
        }
        return true;
    }
};