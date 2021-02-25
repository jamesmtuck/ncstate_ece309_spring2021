#include <iostream>


void increment_cstyle(int *vptr)
{
  (*vptr)++;
}

void increment(int &v)
{
  v++;
}

int main()
{
  int *array = new int [1000];
  
  int x = 0;
  int &y = x; // y is just another name for x

  std::cout << "x = " << x << " &x = " << &x << std::endl;
  std::cout << "y = " << y << " &y = " << &y << std::endl;

  increment(x);

  increment_cstyle(&x);
  
  std::cout << "x = " << x << " &x = " << &x << std::endl;

  return 0;
}
