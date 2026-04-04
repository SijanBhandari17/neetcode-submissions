class StockSpanner {
private:
    int count ;
    stack<pair<int,int>> st;
public:
    StockSpanner() {
         count = 1;
     }

    int next(int price) {
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }
        int res;
        if(st.empty()){
            res = count;
        }
        else{
            res = count - st.top().second;
        }
        st.push({price,count++});
        return res;
    }
};


/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */