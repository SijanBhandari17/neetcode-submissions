class Solution {
public:
int eval(int a, int b , string oper){
    int result = 0;
    switch(oper[0]){
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            result = a / b;
            break;
    }
    return result;
}

int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for(const string c: tokens){
        if(c != "+" && c != "-" && c != "/" && c != "*"){
            st.push(stoi(c));
        }
        else{
            int top = st.top();
            st.pop();
            int last = st.top();
            st.pop();
            int result = eval(last, top, c);
            st.push(result);
        }
    }
    return st.top();
}
};
