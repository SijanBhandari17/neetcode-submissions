class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
  int f = m - 1;
  int s = n - 1;
  int i = m +n - 1;
    while(f >= 0 and s >=0) {
        if (nums1[f] < nums2[s]) 
            nums1[i--] = nums2[s--];
        else 
            nums1[i--] = nums1[f--];
    }
    while(s >=0){
        nums1[i--] = nums2[s--];
    }
    
    }
};