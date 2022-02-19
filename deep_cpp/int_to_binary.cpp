#include <iostream>
#include <string>

void int_to_binary_str(int x) {
  std::cout << "Hi" << std::endl;
  std::string s = "";
  while (x != 0) {
    if (x & 1) {
      s = '1' + s; 
    } else {
      s = '0' + s; 
    }
    x >> 1;
  }
  std::cout << s << std::endl;
}

int main () {
  std::cout << "hfwae" << std::endl;
  int_to_binary_str(9);
}
