#include "Serializer.hpp"

int main() {
  Data object;
  
  // uintptr_t serialized = Serializer::serialize(&object);
  std::cout << &object << std::endl;
  Data* ptr = Serializer::deserialize(Serializer::serialize(&object));
  std::cout << ptr << std::endl;
}