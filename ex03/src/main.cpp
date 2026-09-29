#include <iostream>
#include <string>
#include <string_view>
#include <format>

void streamInsertion(std::string_view quote, std::string_view author) {
  std::cout << author << " says, " << '"' << quote << '"' << std::endl;
}

void stringConcatenation(std::string quote, std::string author) {
  std::string quoteWithMarks{'"' + quote + '"'};
  std::string final{author + " says, " + quoteWithMarks};
  std::cout << final << std::endl;
}

void stringInterpolation(std::string quote, std::string author) {
  std::string formatted{std::format("{} says, {}{}{}", author, '"', quote, '"')};
  std::cout << formatted << std::endl;
  
}

int main() {
  std::string divider{"--------------------\n"};
  std::string quote, author{};
  std::cout << "What is the quote?: ";
  std::getline(std::cin, quote);
  std::cout << "Who said it?: ";
  std::getline(std::cin, author);
  
  std::cout << "Stream Insertion\n" << divider;
  streamInsertion(quote, author);
  std::cout << "String Concatenation\n" << divider;
  stringConcatenation(quote, author);
  std::cout << "String Interpolation\n" << divider;
  stringInterpolation(quote, author);
  return 0;
}

// TODO: challenge
