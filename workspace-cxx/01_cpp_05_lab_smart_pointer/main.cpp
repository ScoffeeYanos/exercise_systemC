#include "smart_ptr.h"
#include "vehicles.h"
#include <iostream>

int main()
{
  smart_ptr<car>     ptr1(new car(black));
  smart_ptr<jet>     ptr2;
  smart_ptr<vehicle> ptr3(ptr1);
  smart_ptr<vehicle> ptr4(ptr3);
  
  ptr3 = ptr1;
  ptr4 = ptr2 = new jet(silver);

  ptr1->set_speed(12, 1);
  ptr2->set_speed(60, 80, 5);
    
  smart_ptr<int> ptr5(new int);
  *ptr5 = 42;
  
  std::cout << "*ptr3 = " << *ptr3 << std::endl;
  std::cout << "*ptr4 = " << *ptr4 << std::endl;
  std::cout << "*ptr5 = " << *ptr5 << std::endl;

  return 0;
}
