class Solution {
public:
    int mySqrt(int x) {
    uint32_t r = x;    
    while((long long) r * r > x){
        r = (r + x / r) >> 1;
    }
    return r;

          
}
};