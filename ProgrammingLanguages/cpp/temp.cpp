// set_terminate example
#include <iostream>       // std::cerr
#include <exception>      // std::set_terminate
#include <cstdlib>        // std::abort

void myterminate () {
  std::cout << "terminate handler called\n";
}

int main (void) {
  std::set_terminate (myterminate);
  throw 0;  // unhandled exception: calls terminate handler
  std::cout << "Zinda hu me" << std::endl;
  return 0;
}
