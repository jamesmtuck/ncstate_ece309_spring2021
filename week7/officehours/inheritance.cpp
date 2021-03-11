#include <iostream>
using namespace std;

class Base_Class
{
public:
  int x;
public:
  virtual int get() {
    std::cout << "called Base_Class::get()" << std::endl;
    return x;
  }
};

// Derived_Class is a Base_Class
class Derived_Class : public Base_Class
{
public:
  int y;
  Derived_Class(){
    x = 10;
  }
  virtual int get() {
    std::cout << "called Derived_Class::get()" << std::endl;
    return y;
  }
};



int main()
{
  //Derived_Class * d = new Base_Class();
  //d->y = 3;
  
  Derived_Class *d = new Derived_Class();
  Base_Class *b = d;
  b->x = 5;
  //b->y = 6;//fail - syntax error

  d->x = 6;
  d->y = 7;
  std::cout << b->get() << std::endl;
  std::cout << d->get() << std::endl;
  
  std::cout << " " << d->y << std::endl;
  
  return 0;
}
