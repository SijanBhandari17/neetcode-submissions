class Solution {
public:


    int partition(vector<int> &nums,int p, int r){
        int i = p - 1;
        int j; 
        int pivot = nums[r];
        for(j = p; j < r ;j++){
            if(nums[j] < pivot){
                i++;
                swap(nums[j], nums[i]);
            }
        }
        swap(nums[i + 1],nums[r]);
        return i + 1;
    }

    void quickSort(vector<int> &nums,int p,int r){
        if(p < r){
            int pivot = partition(nums,p,r);
            quickSort(nums,p , pivot - 1);
            quickSort(nums,pivot + 1, r);
        }

    }
    vector<int> sortArray(vector<int>& nums) {
       quickSort(nums,0,nums.size() - 1); 
       return nums;
    }
};