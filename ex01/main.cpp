#include <iostream>
#include <string>
#include <sstream>

void sayHello() {
  std::cout << "What is your name: ";
  std::string name {};
  std::getline(std::cin >> std::ws, name);
  std::cout << "Hello " << name << '!';
}

void noVariablesHello() {
  std::stringstream ss{std::string{}};
  std::cout << "What is your name: ";
  // TODO: CHALLENGES
}

int main() {
  sayHello();
  return 0;
}
