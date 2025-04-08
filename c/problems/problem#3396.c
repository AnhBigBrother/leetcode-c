int minimumOperations(int *nums, int numsSize) {
  int count[101];
  int distinct = 0;
  int i = 0;
  int ans = 0;
  for (int i = 0; i < 100; i++) {
    count[i] = 0;
  }
  for (int i = 0; i < numsSize; i++) {
    count[nums[i]]++;
    if (count[nums[i]] == 1) {
      distinct++;
    }
  }
  while (numsSize > distinct) {
    for (int j = 0; j < 3; j++) {
      if (numsSize > 0) {
        count[nums[i]]--;
        if (count[nums[i]] == 0) {
          distinct--;
        }
        numsSize--;
        i++;
      }
    }
    ans++;
  }
  return ans;
}
