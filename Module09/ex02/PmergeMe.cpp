#include "PmergeMe.hpp"

std::vector<int>  divide(std::vector<int>& nums) {
  if (nums.size() <= 1)
    return nums;

  std::vector<int> bigger;
  std::vector<int> smaller;

  for (int i = 0; i < nums.size(); i++) {
    if (i + 1 < nums.size()) {
      if (nums[i] > nums[i + 1]) {
        bigger.push_back(nums[i]);
        smaller.push_back(nums[i + 1]);
      }
      else {
        bigger.push_back(nums[i + 1]);
        smaller.push_back(nums[i]);
      }
    }
    else
      bigger.push_back(nums[i]);
  }

  std::vector<int> sorted_half = divide(bigger);
}