#include  "easyfind.hpp"
#include <vector>
#include <map>


int main () {

  std::vector<int> so;

  so.push_back(1);
  so.push_back(2);
  so.push_back(3);
  so.push_back(4);
  so.push_back(5);
  so.push_back(6);

  try {
  std::cout << *easyfind(so, 2) << std::endl;
  } catch (...) {
    std::cout << "Not found" << std::endl;
  }
}