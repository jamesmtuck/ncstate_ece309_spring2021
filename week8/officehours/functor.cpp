#include <iostream>
#include <string>
using namespace std;

class Functor {
public:
  Functor(string init=""):s(init){}
  std::string s;
  void operator() (void)
  {
    std::cout << "Hello, " << s << "!" << std::endl;
  }
};

class FunctorWithArg {
public:
  FunctorWithArg(string init=""):s(init){}
  std::string s;
  void operator() (std::string b)
  {
    std::cout << "Hello, " << s << " and " << b << "!" << std::endl;
  }
};

void PassInFunctor(Functor &F)
{
  F();
}

template<typename X>
class UsesAFunctor {
  X f;
public:
  UsesAFunctor(X af):f(af){}
  void run() { f(); }
};

class Date {
public:
  Date(int d, int m, int y)
    :day(d),month(m),year(y) {}
  int day;
  int month;
  int year;
};

class MyCompare {
public:
  bool operator() (const Date &d1, const Date &d2)
  {
    if (d1.year < d2.year) {
      return true;
    } else if (d1.year==d2.year) {
      if (d1.month < d2.month)
	return true;
      else if (d1.month == d2.month)
	{
	  if (d1.day < d2.day)
	    return true;	  
	}      
    }
    return false;
  }
};

int main()
{
  Functor f1("James");
  Functor f2("Ben");
  
  PassInFunctor(f2);
  PassInFunctor(f1);

  UsesAFunctor<Functor> u(Functor("Wolfpack"));
  u.run();

  FunctorWithArg f3("James");
  f3("Ben");

  Date d1(3,11,2021);
  Date d2(3,11,2021);

  MyCompare comp;

  if (comp(d1,d2))
    std::cout << "March 11, 2021 comes before March 11, 2021?" << std::endl;
  else
    std::cout << "We don't a bug!" << std::endl;
  
  return 0;
}
