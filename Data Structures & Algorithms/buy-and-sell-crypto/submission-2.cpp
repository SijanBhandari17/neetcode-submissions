class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int l = 0;
        int r = 1;
        int max = 0;
        while(r < n){
            int profit = prices[r] - prices[l];
            if(profit > 0){
                max = profit > max ? profit : max;
            }else{
                l = r;
            }
            r++;
        }
        return max;
    }
};
