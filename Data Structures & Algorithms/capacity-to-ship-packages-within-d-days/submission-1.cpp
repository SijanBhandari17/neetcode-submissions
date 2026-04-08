class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(),weights.end());
        int r = accumulate(weights.begin(),weights.end(),0);
        int res = l;
        while(l <= r){
            int mid = l + (r - l ) / 2;
            int n = weights.size();
            int count = 1;
            int i;
            int curr_weight = 0;
            for(i = 0; i < weights.size();i++){
                if(curr_weight + weights[i] > mid ){
                    count++;
                    curr_weight = weights[i];
                }
                else{
                    curr_weight += weights[i]; 
                }
            }
            if(count > days){
                l = mid + 1;
            }  
            else{
                res = mid;
                r = mid - 1;
            }
            
        }
        return res;
    }
};