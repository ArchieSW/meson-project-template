#include <iostream>
#include "bar/bar.h"
#include "foo/foo.h"

int main() {
  std::cout << "Hello world!" << std::endl;
  std::cout << "FOO : " << foo(1) << std::endl;
  std::cout << "BAR : " << bar(2) << std::endl;
}
