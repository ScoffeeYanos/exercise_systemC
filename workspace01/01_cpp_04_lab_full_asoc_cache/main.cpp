#include "complex.h"
#include "full_asoc_cache.h"

#include <iostream>

int main()
{
  full_asoc_cache<int, complex> cache(4);
  
  for(int i = 0; i < 4; i++) {
    cache.insert(i, complex(10.1+i, i/10.0));
  }
  
  cache.erase(3);
  cache.insert(4, complex(14.1, 0.4));
  cache.insert(5, complex(15.1, 0.5));
  
  for(int i = 0; i < 6; i++) {
    complex tmp;
    if(cache.get(i, tmp))
      std::cout << tmp << std::endl;
  }
  
  cache.clear();
  
  for(int i = 0; i < 6; i++) {
    complex tmp;
    if(cache.get(i, tmp))
      std::cout << tmp << std::endl;
  }
  
  return 0;
}
