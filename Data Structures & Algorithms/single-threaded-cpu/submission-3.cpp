class Solution {
public:
    vector<int> getOrder(vector<vector<int>> &tasks) {
        vector<tuple<int,int,int>> jobs;
        vector<int> output;

        for (int i = 0; i < tasks.size(); i++) {
            jobs.push_back({tasks[i][0], tasks[i][1], i});
        }
        sort(jobs.begin(), jobs.end(),
             [](const tuple<int,int,int> &a, const tuple<int,int,int> &b) { return get<0>(a) < get<0>(b); });

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;

        int i = 0;
        long long time = 0;
        while (i < jobs.size() || !heap.empty()) {
            if (heap.empty() && time < get<0>(jobs[i])) {
                time = get<0>(jobs[i]);
            }
            while (i < jobs.size() && get<0>(jobs[i]) <= time) {
                heap.push({get<1>(jobs[i]), get<2>(jobs[i])});
                i++;
            }
            pair<int,int> task = heap.top();
            heap.pop();
            time += task.first;
            output.push_back(task.second);
        }
        return output;
    }
};