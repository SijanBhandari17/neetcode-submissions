class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
stack<int> st;
    for(int i = 0; i < asteroids.size(); i++){
        bool destroyed = false;
        if(!st.empty() && asteroids[i] < 0 && st.top() > 0 ){
            while(!st.empty() && st.top() > 0) {
                if(st.top() == abs(asteroids[i])){
                    st.pop();
                    destroyed = true;
                    break;
                }
                else if(st.top() < abs(asteroids[i])){
                    st.pop();
                }
                else{
                    destroyed = true;
                    break;
                }
            }
            if(!destroyed) st.push(asteroids[i]);
        }
        else{
            st.push(asteroids[i]);
        }
    }

    int n = st.size();
    vector<int> result(n);

    for (int i = n - 1; i >= 0; i--) {
        result[i] = st.top();
        st.pop();
    }
    return result;    }
};