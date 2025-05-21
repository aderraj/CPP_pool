#include "PmergeMe.hpp"

int main (int ac, char **av) {
  if (ac < 2)
    return (std::cerr << "Error: insufficient args!\n", 0);

  std::vector<int> nums;
  try { nums = getSequence<std::vector<int> >(ac, av); }
  catch (std::exception& e) {
    return (std::cerr << e.what() << std::endl, 0);
  }
  
  if (isSorted(nums))
    return (std::cerr << "Error: already sorted!\n", 0);
  std::cout << "Before: ";
  printSequence< std::vector<int> >(nums);

  clock_t start_vector = clock();
  std::vector<int> sorted_vector = vectorMergeInsertSort(nums);
  clock_t end_vector = clock();

  std::cout << "After:  ";
  printSequence< std::vector<int> >(sorted_vector);

  double time_vector = static_cast<double>(end_vector - start_vector) / CLOCKS_PER_SEC * 1e6;
  std::cout << std::fixed << std::setprecision(6);
  std::cout << "Time to process a range of " << nums.size() 
            << " elements with std::vector: " << time_vector << " us" << std::endl;

  std::deque<int> nums_deque = getSequence<std::deque<int> >(ac, av);

  clock_t start_deque = clock();
  std::deque<int> sorted_deque = dequeMergeInsertSort(nums_deque);
  clock_t end_deque = clock();

  double time_deque = static_cast<double>(end_deque - start_deque) / CLOCKS_PER_SEC * 1e6;
  std::cout << "Time to process a range of " << nums_deque.size() 
            << " elements with std::deque: " << time_deque << " us" << std::endl;

  return 0;
}