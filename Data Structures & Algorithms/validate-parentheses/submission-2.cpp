class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size();i++){
            if(s[i] == '}' || s[i] == ']' || s[i] == ')'){
                if(st.empty()) return false;
                char a = st.top();
                st.pop();
                if(s[i] == '}' && a == '{') continue;
                else if(s[i] == ']' && a == '[') continue;
                else if(s[i] == ')' && a == '(') continue;
                else return false;
            }
            else{
                st.push(s[i]);
            }

        }
        return st.empty();
    }
};
