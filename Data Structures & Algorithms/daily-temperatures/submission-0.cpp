class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        deque<pair<int,int>> st;
        vector<int> output(n);
        for(int i = n - 1; i >= 0;i--){
            bool greater_found = false;
            for (auto it = st.rbegin(); !st.empty() && it != st.rend(); ++it) {
                if(temperatures[i] > it->first){
                    st.pop_back();
                }
                else if(temperatures[i] < it->first){
                    greater_found = true;
                    output[i] = it->second - i;
                    break;
                }
            }
            if(!greater_found) output[i] = 0;

            st.push_back({temperatures[i],i});
        }
        return output;
    }
};
