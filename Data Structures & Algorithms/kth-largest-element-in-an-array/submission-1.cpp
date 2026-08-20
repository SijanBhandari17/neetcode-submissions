class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int n = nums.size();
        int right = nums.size() - 1;

        while (left <= right) {
            int pivotIndex = partition(left, right, nums);
            cout << nums[pivotIndex];
            cout << pivotIndex;
            if (n - pivotIndex == k) {
                return nums[pivotIndex];
            } else if (n - pivotIndex > k ) {
                left = pivotIndex + 1;
            } else {
                right = pivotIndex - 1;
            }
        }
        
        return nums[0];
  
    }
    int partition(int low, int high, vector<int>& distance) {
        int pivot  = distance[high];
        int i = low;
        for (int j = low; j < high; j++) {
            if (distance[j] <= pivot) {
                swap(distance[i], distance[j]);
                i++;
            }
        }
        swap(distance[i], distance[high]);
        return i;
    }
};
