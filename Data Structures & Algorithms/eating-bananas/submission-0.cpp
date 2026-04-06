class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
    int n = piles.size();
    int r = *max_element(piles.begin(),piles.end());
    int l = 1;
    int k = r;
    while(l <= r){
        int mid = ( l + r )/ 2;
        int t = 0;
        
        for(int i = 0; i < n;i++){
            t += (piles[i] + mid - 1) / mid;
        }
        
        if(t <= h){
            k = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return k;
    }
};
