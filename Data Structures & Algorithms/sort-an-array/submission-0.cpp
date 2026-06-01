class Solution {
   public:
    void mergeSort(vector<int>& nums, int p, int r) {
        if (p < r) {
            int q = floor((p + r) / 2);
            mergeSort(nums, p, q);
            mergeSort(nums, q + 1, r);
            merge(nums, p, q, r);
        }
    }
    void merge(vector<int>& nums, int p, int q, int r) {
        vector<int> left;
        vector<int> right;

        int i, j;
        for (i = p; i <= q; i++) left.push_back(nums[i]);
        for (j = q + 1; j <= r; j++) right.push_back(nums[j]);
        left.push_back(INT_MAX);
        right.push_back(INT_MAX);
        i = 0;
        j = 0;
        for (int k = p; k <= r; k++) {
            if (left[i] < right[j]) {
                nums[k] = left[i];
                i++;
            } else {
                nums[k] = right[j];
                j++;
            }
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};