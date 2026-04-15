class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n -1;

        while(l < r){
            int mid = l + ( r - l)/2;
            if(nums[r] > nums[mid]){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }

        int sm = l;
        r = n - 1;

        if(nums[sm] <= target && nums[r] >= target ){
            l = sm;
        }
        else{
            r = sm - 1;
            l = 0;

        }

        while(l <= r){
            int mid = l + ( r - l)/ 2;
            if(nums[mid] ==  target) return mid;
            if(nums[mid] > target) {
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return -1;
    }
};
