#include <iostream>

using namespace std;

void myownscan(int &z)
{
  scanf("%d",&z);
}

void myownscan_cstyle(int *z)
{
  scanf("%d",z);
}

int main() {
  
  int x = 10;
  int &y = x;

  int *ptr = nullptr;
  ptr = &x;
  
  std::cout << "x = " << x << std::endl;
  std::cout << "y = " << y << std::endl;
  std::cout << "addressof(x) = " << &x << std::endl;
  std::cout << "addressof(y) = " << &y << std::endl;

  std::cout << "ptr = " << ptr << std::endl;
  std::cout << "*ptr = " << *ptr << std::endl;

  scanf("%d", ptr);

  std::cout << "y = " << y << std::endl;
  
  myownscan(x);

  std::cout << "x = " << x << std::endl;

  myownscan_cstyle(&x);
  std::cout << "x = " << x << std::endl;

  
  return 0;
}
