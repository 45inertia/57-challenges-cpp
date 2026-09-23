#include <iostream>
#include <string>

int main() {
  std::cout << "What is your name: ";
  std::string name {};
  std::getline(std::cin >> std::ws, name);
  std::cout << "Hello " << name << '!';
  return 0;
}
