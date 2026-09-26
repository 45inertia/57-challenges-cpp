#include <iostream>
#include <string>

int main() {
  std::string input{};
  std::cout << "Input String: ";
  while (true) {
    if (!std::getline(std::cin, input)) {
      std::cout << "Please enter a valid string: ";
    } else if (input.empty()) {
      std::cout << "Please enter a valid string: ";
    } else {
      break;
    }
  }
  std::cout << input << " has " << input.size() << " characters.\n";

  std::cout << input << " has " << input.length() << " characters.\n";
  return 0;
}
