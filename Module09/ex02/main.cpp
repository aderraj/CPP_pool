#include "PmergeMe.hpp"

int main () {
  std::vector<int> nums;
  nums.push_back(7);
  nums.push_back(3);
  nums.push_back(9);
  nums.push_back(1);
  nums.push_back(5);
  nums.push_back(6);
  nums.push_back(2);

  std::vector<int> x =  mergeInsertSort(nums);
  for (size_t i = 0; i < x.size(); i++)
    std::cout << x[i] << ", ";
  std::cout << std::endl;
}