class Solution {

   public:
bool dfs(vector<int> &nums, int target, int idx, int sum, int bucket, int k,
         vector<bool> &marked) {

  if (sum == target) {
    bucket++;

    if (bucket == k)
      return true;

    return dfs(nums, target, 0, 0, bucket, k, marked);
  }

  if (idx >= nums.size())
    return false;

  if (marked[idx])
    return dfs(nums, target, idx + 1, sum, bucket, k, marked);

  if (sum + nums[idx] <= target) {

    marked[idx] = true;

    if (dfs(nums, target, idx + 1, sum + nums[idx], bucket, k, marked))
      return true;

    marked[idx] = false;
  }

  return dfs(nums, target, idx + 1, sum, bucket, k, marked);
}

bool canPartitionKSubsets(vector<int> &nums, int k) {

  int total = accumulate(nums.begin(), nums.end(), 0);

  if (total % k != 0)
    return false;

  int target = total / k;

  sort(nums.begin(), nums.end(), greater<int>());

  vector<bool> marked(nums.size(), false);

  return dfs(nums, target, 0, 0, 0, k, marked);
}

};