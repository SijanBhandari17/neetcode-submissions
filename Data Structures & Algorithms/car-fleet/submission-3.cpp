class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<pair<int,double>> st;
        vector<pair<int,double>> cars;

        for(int i = 0; i < position.size() ;i ++){
            cars.push_back({position[i],(double)(target - position[i])/ speed[i]});
        }
        sort(cars.begin(),cars.end());

        for(int i = cars.size() - 1; i >= 0 ; i--){
            if(st.empty()) {
                st.push(cars[i]);
                continue;
            }
            if(st.top().second < cars[i].second)
            st.push(cars[i]);
        }
        return st.size();




    }
};
