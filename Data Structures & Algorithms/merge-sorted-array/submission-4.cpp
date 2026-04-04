class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
  int f = m - 1;
  int s = n - 1;
  if (n == 0)
    return;
  for (int i = m + n - 1; i >= 0 && s >= 0; i--) {
    if (f >= 0) {
      if (nums1[f] < nums2[s]) {
        nums1[i] = nums2[s];
        s--;
      } else {
        nums1[i] = nums1[f];
        f--;
      }
    } else {
      nums1[i] = nums2[s];
      s--;
    }
  }
    }
};