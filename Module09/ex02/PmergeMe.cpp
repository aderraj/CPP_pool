#include "PmergeMe.hpp"

/*
  get the order to insert the pending elements
    to minimize the comparisons necessary for
    the binary search insertion.
  (using the Jacobsthal Sequence)
*/

std::vector<size_t> getInsertionOrder(size_t size) {
  
  std::vector<size_t> indices;
  if (size < 1)
    return indices;
  
  // gets the corresponding Jacobsthal sequence values
  size_t n_2 = 1, n_1 = 1;
  while (n_1 <= size) {
    indices.push_back(n_1 - 1);
    size_t next = n_1 + 2 * n_2;
    n_2 = n_1;
    n_1 = next;
  }

  // fill in the remaning indices
  size_t j = 0;
  for (size_t i = 0; i < size; i++) {
    if (j < indices.size() && i == indices[j])
      { j++; continue; }
    else
      indices.push_back(i);
  }
  return (indices);
}

std::vector<int>  vectorMergeInsertSort(const std::vector<int>& nums) {

  size_t size = nums.size();

  if (size <= 1)
    return nums;
  std::vector<int> main_chain;
  std::vector<int> pending_chain;

  /*
    virtualy divide the sequence into pairs, sort each pair
                              and push it to the main chain
    (instead of creating std::pair for example to form pairs,
      just use the original sequence and compare each element
      with it's pair to form a main chain)
  */
  for (size_t i = 0; i + 1 < size; i += 2) {
    if (nums[i] > nums[i + 1]) {
      main_chain.push_back(nums[i]);
      pending_chain.push_back(nums[i + 1]);
    }
    else {
      main_chain.push_back(nums[i + 1]);
      pending_chain.push_back(nums[i]);
    }
  }

  // append the unpaired element to the pending sequence
  if (size % 2)
    pending_chain.push_back(nums.back());

  // sort the chain that contains the max elements
  main_chain = vectorMergeInsertSort(main_chain);

  /* insert the pending elements using binary search
    following the jacobsthal sequence based order,
    to perform the least number of comparisons.
  */
  std::vector<size_t> insert_order = getInsertionOrder(pending_chain.size());
  for (size_t i = 0; i < insert_order.size(); i++)
    binaryInsert(main_chain, pending_chain[insert_order[i]]);

  return main_chain;
}

std::deque<int>   dequeMergeInsertSort(const std::deque<int>& nums) {
  
  size_t size = nums.size();
  if (size <= 1)
    return nums;

  std::deque<int> main_chain;
  std::deque<int> pending_chain;

  for (size_t i = 0; i + 1 < size; i += 2) {
    if (nums[i] > nums[i + 1]) {
      main_chain.push_back(nums[i]);
      pending_chain.push_back(nums[i + 1]);
    }
    else {
      main_chain.push_back(nums[i + 1]);
      pending_chain.push_back(nums[i]);
    }
  }

  if (size % 2)
    pending_chain.push_back(nums.back());

  main_chain = dequeMergeInsertSort(main_chain);

  std::vector<size_t> insert_order = getInsertionOrder(pending_chain.size());
  for (size_t i = 0; i < insert_order.size(); i++)
    binaryInsert(main_chain, pending_chain[insert_order[i]]);

  return main_chain;
}