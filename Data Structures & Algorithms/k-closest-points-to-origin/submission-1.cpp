class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<float, vector<float>> pq;
        unordered_multimap<float,vector<int>> hash_set;

        for(const auto &num :points){
            float dis = sqrt(num[0] * num[0] + num[1] * num[1]);
            pq.push(dis);
            hash_set.insert(make_pair(dis,num));
            if(pq.size() > k && dis <= pq.top()){
                hash_set.erase(pq.top());
                pq.pop();
            }
        }
        vector<vector<int>> o;
        for(const auto &par : hash_set){
            cout << par.first;
            o.push_back(par.second);
        }
        return o;
        
    }
};

