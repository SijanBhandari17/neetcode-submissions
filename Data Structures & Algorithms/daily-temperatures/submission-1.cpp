class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int,int>> st;
        vector<int> output(n);
        for(int i = n - 1; i >= 0;i--){
            while(!st.empty() && st.top().first <= temperatures[i]){
                st.pop();
            }
            if(!st.empty()){
                output[i] = st.top().second - i;
            }
            st.push({temperatures[i],i});
        }
        return output;
    }
};
