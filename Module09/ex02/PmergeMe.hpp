#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <deque>
#include <ctime>
#include <iomanip> 

std::vector<int>  vectorMergeInsertSort(const std::vector<int>& nums);
std::deque<int>   dequeMergeInsertSort(const std::deque<int>& nums);

template <typename T>
bool isSorted(const T& container) {
  return (std::adjacent_find(container.begin(),
                             container.end(),
                             std::greater<typename T::value_type>())
                            == container.end());
}

template <typename T>
  void  binaryInsert(T& chain, int n) {
    chain.insert(std::lower_bound(chain.begin(), chain.end(), n), n);
}

template <typename T>
  T getSequence(int argc, char* argv[]) {
    T sequence;
  
    for (int i = 1; i < argc; ++i) {
        std::istringstream stream(argv[i]);
        int number;
  
        if (!(stream >> number) || !stream.eof()) {
            throw std::invalid_argument("Error: Invalid input detected in arguments.");
        }
  
        sequence.push_back(number);
    }
    return sequence;
}

template <typename T>
  void  printSequence(T& sequence) {
    for (typename T::iterator it = sequence.begin(); it != sequence.end(); it++)
      std::cout << *it << ((it + 1 != sequence.end()) ? " " : "");
    std::cout << std::endl;
}

#endif