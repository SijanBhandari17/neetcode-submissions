class Solution {
public:
    void rotate(vector<int>& nums, int k) {


  int n = nums.size();
  k = k % n;
  if (k == 0)
    return;


  int count = 0;
  for (int start = 0; count < n; start++) {
    int kun = start;
    int temp1 = nums[start];
    do {
      int kaha = (kun + k) % n;
      int temp = nums[kaha];
      nums[kaha] = temp1;
      temp1 = temp;
      kun = kaha;
      count++;
    } while (start != kun);
  }
  return;

}};