#include <iostream>
#include <string>
#include <random>

std::string getInput(std::string_view inputType) {
  std::string input{};
  std::cout << "Enter a " << inputType << ": ";
  std::getline(std::cin, input);
  return input;
}

std::string getMadLibTemplate() {
  return "incomplete";
}

int returnRandNum() {
  std::random_device rd;
  std::mt19937 gen(rd());
  return gen();
}

int main() {
  for(int i = 0; i < 5; ++i) {
    std::cout << returnRandNum() << '\n';
  }
  std::string noun{getInput("noun")};
  std::string verb{getInput("verb")};
  std::string adjective{getInput("adjective")};
  std::string adverb{getInput("adverb")};
  return 0;
}
