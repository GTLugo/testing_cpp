//
// Created by galex on 10/7/2022.
//

#include "lib.hpp"
#include <koyote/utilities.hpp>

namespace lib {
  void testing()
  {
  
    int a = 5;
    int& b = a;
    b = 6;
    
    int* c = &a;
    
    std::cout << a << ' ' << b << ' ' << *c << '\n';
    
  }
} // lib