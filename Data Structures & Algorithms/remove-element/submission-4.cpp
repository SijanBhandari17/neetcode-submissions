class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    //     if(nums.size() == 0) return 0;

    //     auto fp = nums.begin();
    //     auto lp = nums.end() - 1;
    //     int count = 0;
    //     while(*(lp) == val){
    //         lp--;
    //         count++;
    //     }
    //     while(fp < lp){
    //         if(*fp == val){
    //             swap(*fp,*lp);
    //             while(*(lp) == val){
    //                 lp--;
    //                 count++;
    //             }   
    //         }
    //         fp++;
    //     }
    // return nums.size() - count;

    int k =0;
    for(const int num : nums){
        if(num != val) {
            nums[k] = num;
            k++;
        }
    }
    return k;
    }
};