#include "iter.hpp"

template <typename T>
void function(T& elem) {
  std::cout << elem;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  char arr2[] = {'a', 'b', 'c', 'd', 'e'};
  std::string strs[] = {"this", " is ", "a ", "test", "!"};

  iter<int>(arr, sizeof(arr) / sizeof(arr[0]), function);
  std::cout << std::endl;

  iter<char>(arr2, sizeof(arr2) / sizeof(arr2[0]), function);
  std::cout << std::endl;

  iter<std::string>(strs, sizeof(strs) / sizeof(strs[0]), function);
  std::cout << std::endl;

}