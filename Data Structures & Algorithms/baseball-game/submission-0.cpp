class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        for(int i = 0; i < operations.size();i++){
            if(operations[i] == "D"){
                s.push(s.top()* 2);
            }
            else if(operations[i] == "C"){
                s.pop();
            }
            else if(operations[i] == "+"){
                int a = s.top();
                s.pop();
                int sum = a + s.top();
                s.push(a);
                s.push(sum);
            }
            else{
                    s.push(stoi(operations[i]));
            }
        }
        int total = 0;

while (!s.empty()) {
    total += s.top();
    s.pop();
}

return total;
    }
};